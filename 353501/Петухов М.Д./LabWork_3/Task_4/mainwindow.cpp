#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QThread>
#include <QGraphicsScene>
#include <QTableWidgetItem>

MainWindow::MainWindow() : ui(new Ui::MainWindow), scene(new QGraphicsScene(this))
{
  setAttribute(Qt::WA_DeleteOnClose);
  ui->setupUi(this);

  ui->graphicsView->setScene(scene);
  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
  scene->setSceneRect((ui->graphicsView->width() - 20) / -2, -20, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
  connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::on_spinBox_valueChanged);

  towers = new HanoiTowers();
  scene->addItem(towers);

}

MainWindow::~MainWindow()
{
  
}

void MainWindow::hanoi(int n, int start, int end)
{
  if (n == 1)
  {
    moveDisk(n, start, end);
  }
  else
  {
    int other = 6 - start - end;
    hanoi(n - 1, start, other);
    moveDisk(n, start, end);
    hanoi(n - 1, other, end);
  }
}

void MainWindow::calculatePrePositions(){
    towers->minDiskPosOnStick[0] = 480;
    towers->minDiskPosOnStick[1] = 480;
    towers->minDiskPosOnStick[2] = 480;

    onFirst = 0;
    onSecond = 0;
    onThird = 0;

    for(int i = 10 - N; i < 10; i++){
        if(towers->posX[i] == towers->towerStickX[0] + 10 - towers->diskWidth[i] / 2){
          onFirst++;
        }
        else if(towers->posX[i] == towers->towerStickX[1] + 10 - towers->diskWidth[i] / 2){
          onSecond++;
        }
        else if(towers->posX[i] == towers->towerStickX[2] + 10 - towers->diskWidth[i] / 2){
          onThird++;
        }
    }

    towers->minDiskPosOnStick[2]-=towers->getDiskHeight() * onThird;
    towers->minDiskPosOnStick[1]-=towers->getDiskHeight() * onSecond;
    towers->minDiskPosOnStick[0]-=towers->getDiskHeight() * onFirst;

    towers->stop = false;
}

void MainWindow::moveDisk(int n, int start, int end)
{

    calculatePrePositions();

    towers->stop = false;
    while(!towers->stop){
      towers->animate(10 - n, start, end);
      QCoreApplication::processEvents();
      QThread::msleep(speed);
    }

  ui->tableWidget->insertRow(movesCount);
  QTableWidgetItem* itm = new QTableWidgetItem(QString::number(start));
  ui->tableWidget->setItem(movesCount, 0, itm);
  itm = new QTableWidgetItem(QString("->"));
  ui->tableWidget->setItem(movesCount, 1, itm);
  itm = new QTableWidgetItem(QString::number(end));
  ui->tableWidget->setItem(movesCount, 2, itm);
  movesCount++;


  update();
}

void MainWindow::on_pushButton_clicked()
{
  towers->isChanging = false;

  ui->pushButton->hide();
  ui->spinBox->hide();

  hanoi(N, 1, 3);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
  N = arg1;
  towers->setN(arg1);
  QCoreApplication::processEvents();
  update();
}

