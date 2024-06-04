#include "mainwindow.h"
#include "Search.h"
#include "Sorter.h"
#include "VisVector.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <qcombobox.h>
#include <qgraphicsscene.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qtablewidget.h>
#include <qtimer.h>

MainWindow::MainWindow()
    : ui(new Ui::MainWindow), scene(new QGraphicsScene), playTimer(new QTimer) {
  ui->setupUi(this);

  // connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onClick);
  connect(ui->inputCount, &QSpinBox::valueChanged, this,
          &MainWindow::fullUpdateVisVector);
  ui->inputCount->setValue(100);
  connect(ui->sortSelect, &QComboBox::currentIndexChanged, this,
          &MainWindow::fullUpdateVisVector);

  connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this,
          &MainWindow::Redraw);
  connect(ui->playBtn, &QPushButton::clicked, this, &MainWindow::playClicked);
  connect(playTimer, &QTimer::timeout, this, &MainWindow::playTicked);

  connect(ui->findBox, &QSpinBox::valueChanged, this,
          &MainWindow::searchUpdateVisVector);

  visvec = nullptr;
  fullUpdateVisVector();

  ui->graphicsView->setScene(scene);
}

void MainWindow::fullUpdateVisVector() {
  int expectedLen = ui->inputCount->value();
  if (!visvec || visvec->Size() != expectedLen) {
    if (visvec)
      delete visvec;

    visvec = new VisVector(expectedLen);
  }
  visvec->Reset();

  if (ui->sortSelect->currentIndex() == 0) {
    Sorter::HeapSort(visvec);
  } else if (ui->sortSelect->currentIndex() == 1) {
    Sorter::QuickSort(visvec);
  } else if (ui->sortSelect->currentIndex() == 2) {
    Sorter::MergeSort(visvec);
  }

  updateVisVector();
  ui->tableWidget->selectRow(0);
}

void MainWindow::searchUpdateVisVector() {
  updateVisVector();
  ui->tableWidget->selectRow(ui->tableWidget->rowCount() - 1);
}

void MainWindow::updateVisVector() {
  visvec->ClearSearch();

  visvec->ReportFind(-100);
  int indexFound = Search::BinSearch(visvec, ui->findBox->value());
  visvec->ReportFind(indexFound, ui->findBox->value());

  visvec->FillTable(ui->tableWidget);

  Stats stats = visvec->CollectStats();
  ui->statsLabel->setText(
      QString("STATS:\nReads: %0\nWrites: %1\nSwaps: %2\nIndex of element: %3")
          .arg(stats.reads)
          .arg(stats.writes)
          .arg(stats.swaps)
          .arg(indexFound));

  Redraw();
}

void MainWindow::onClick() { ui->label->setText("HELLLLOOOO"); }

void MainWindow::playClicked() {
  isPlaying = !isPlaying;
  ui->playBtn->setText(isPlaying ? "PAUSE" : "PLAY");
  if (isPlaying)
    playTimer->start(20);
  else
    playTimer->stop();
}

void MainWindow::playTicked() {
  int curRow = -1;

  auto s = ui->tableWidget->selectedItems();
  if (!s.empty()) {
    curRow = s[0]->row();
  }

  int nextRow = curRow + 1;
  if (nextRow >= ui->tableWidget->rowCount()) {
    isPlaying = false;
    ui->playBtn->setText("PLAY");
    playTimer->stop();
    return;
  }

  ui->tableWidget->selectRow(nextRow);
}

void MainWindow::Redraw() {
  auto s = ui->tableWidget->selectedItems();
  if (!s.empty()) {
    visvec->SetCurrentAction(s[0]->row());
  }

  ui->graphicsView->setUpdatesEnabled(false);
  scene->clear();
  scene->setSceneRect(0, 0, 1024, 600);
  visvec->Draw(scene);
  ui->graphicsView->setUpdatesEnabled(true);
}