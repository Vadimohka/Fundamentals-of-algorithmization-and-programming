#include "mainwindow.h"
#include "SVector.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include "Sorter.h"
#include "Search.h"
#include "Binpow.h"
#include <QMessageBox>


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
  //Sorter::Terminate();
}


void MainWindow::fillTestData(){
  //elements.clear();

  elements.resize(ELEMENTS_SIZE);
  double step = 0.1;
  double initial = 2;
  for(int i = 0; i < ELEMENTS_SIZE; ++i){
    elements.sigSet(i, rand() % 1024);
  }
  
}

void MainWindow::reset(){
  ui->pushButton->setEnabled(false);
  ui->searchBtn->setEnabled(false);
  ui->sortBtn->setEnabled(false);
  clearBinpowLabels();
  if(visualiser){
    visualiser->highligtItem(-1);
  }

  fillTestData();

  ui->sortBtn->setEnabled(true);
  ui->pushButton->setEnabled(true);
  
}

void MainWindow::startSort(){
  timer->restart();
  visualiser->highligtItem(-1);
  ui->sortBtn->setEnabled(false);
  ui->pushButton->setEnabled(false);
  clearBinpowLabels();

  Sorter::InterpSort(elements);

  ui->searchBtn->setEnabled(true);
  ui->pushButton->setEnabled(true);
  ui->timeLbl->setText(QString::number((qreal)timer->elapsed()/1000.));
}

void MainWindow::startSearch(){
  auto val = ui->searchBox->value();
  long ind = Search::binsearch(elements, val);
  
  if(ind == -1L){
    QMessageBox::warning(this, "Info", "Element not found");
    clearBinpowLabels();
  } else {
    visualiser->highligtItem(ind);

    ui->indexLbl->setText(QString::number(ind));
    ui->valLbl->setText(QString::number(ui->searchBox->value()));
    ui->sizeLbl->setText(QString::number(ELEMENTS_SIZE));
    
    auto res = Binpow::get(ind, ELEMENTS_SIZE, val);
    qDebug() << res;
    ui->resultLbl->setText(QString::number(res));
  }
}

void MainWindow::clearBinpowLabels(){
  ui->indexLbl->setText({});
    ui->valLbl->setText({});
    ui->sizeLbl->setText({});
    ui->resultLbl->setText({});
}
