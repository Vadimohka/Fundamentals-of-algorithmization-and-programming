#include "mainwindow.h"
#include "SVector.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include "Sorter.h"
#include "Search.h"
#include <QMessageBox>

enum class SortWay{
  Merge = 0,
  Quick = 1,
  Heap = 2
};

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(geometry().size());
  srand(time(nullptr));
  fillTestData();

  QRectF sceneRect = {0,0, (qreal)ui->visualiser->width(), (qreal)ui->visualiser->height()};
  visualiser.reset(new SortVisualiser(sceneRect, ui->visualiser, this->elements));
  timer.reset(new QElapsedTimer());
  ui->visualiser->scale(1, -1);
  ui->visualiser->setScene(visualiser.data());
  ui->visualiser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  ui->visualiser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  ui->searchBtn->setEnabled(false);

  connect(&elements, &SVector::elementChanged,
          visualiser.data(), &SortVisualiser::updateItem);

  connect(ui->sortBtn, &QPushButton::clicked,
          this, &MainWindow::startSort);

  connect(ui->pushButton, &QPushButton::clicked,
          this, &MainWindow::reset);

  connect(ui->searchBtn, &QPushButton::clicked,
          this, &MainWindow::startSearch);

}

void MainWindow::closeEvent(QCloseEvent* event){
  Sorter::Terminate();
}


void MainWindow::fillTestData(){
  //elements.clear();
  ui->pushButton->setEnabled(false);
  if(visualiser){
    visualiser->highligtItem(-1);
  }
    
  elements.resize(ELEMENTS_SIZE);
  for(int i = 0; i < ELEMENTS_SIZE; ++i){
    elements.sigSet(i, rand() % ELEMENTS_SIZE);
  }
  ui->searchBtn->setEnabled(false);
  ui->pushButton->setEnabled(true);
}

void MainWindow::reset(){
  fillTestData();
  ui->sortBtn->setEnabled(true);
}

void MainWindow::startSort(){
  timer->restart();
  visualiser->highligtItem(-1);
  ui->sortBtn->setEnabled(false);
  ui->pushButton->setEnabled(false);

  switch(ui->comboBox->currentIndex()){
    case (int)SortWay::Merge:
      Sorter::MergeSort(elements);
      break;
    case (int)SortWay::Heap:
      Sorter::HeapSort(elements);
      break;
    case (int)SortWay::Quick:
      Sorter::QuickSort(elements);
      break;
  }

  ui->searchBtn->setEnabled(true);
  ui->pushButton->setEnabled(true);
  ui->timeLbl->setText(QString::number((qreal)timer->elapsed()/1000.));
}

void MainWindow::startSearch(){
  long ind = Search::binsearch(elements, ui->searchBox->value());
  if(ind == -1L){
    QMessageBox::warning(this, "Info", "Element not found");
  } else {
    visualiser->highligtItem(ind);
  }
}
