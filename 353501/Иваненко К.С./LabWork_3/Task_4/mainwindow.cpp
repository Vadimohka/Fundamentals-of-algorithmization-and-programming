#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QThread>
#include <QGraphicsScene>
#include "towers.h"
#include <QTableWidgetItem>

MainWindow::MainWindow() : ui(new Ui::MainWindow), scene(new QGraphicsScene(this))
{
  setAttribute(Qt::WA_DeleteOnClose);
  ui->setupUi(this);

  ui->label_3->hide();
  ui->label_4->hide();

  ui->graphicsView->setScene(scene);
  ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
  scene->setSceneRect((ui->graphicsView->width() - 20) / -2, -20, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
  connect(ui->party, &QPushButton::clicked, this, &MainWindow::on_party_clicked);
  connect(ui->spinBox, &QSpinBox::valueChanged, this, &MainWindow::on_spinBox_valueChanged);
  connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::on_slider_valueChanged);

  towers = new HanoiTowers();
  scene->addItem(towers);

  ui->tableWidget->setColumnCount(4);
  cnt = 1;
}

MainWindow::~MainWindow()
{
}

void MainWindow::hanoi(int n, char source, char auxiliary, char target)
{
  if (n == 1)
  {
    moveDisk(n, source, target);
  }
  else
  {
    hanoi(n - 1, source, target, auxiliary);
    moveDisk(n, source, target);
    hanoi(n - 1, auxiliary, source, target);
  }
}

void MainWindow::moveDisk(int n, char source, char target)
{
  // qDebug() << "Перемещаем диск " << n << " с " << source << " на " << target;
  ui->tableWidget->setRowCount(cnt);
  QTableWidgetItem *itm = new QTableWidgetItem(QString::number(n));
  ui->tableWidget->setItem(cnt - 1, 0, itm);
  itm = new QTableWidgetItem(QString(source));
  ui->tableWidget->setItem(cnt - 1, 1, itm);
  itm = new QTableWidgetItem(QString("->"));
  ui->tableWidget->setItem(cnt - 1, 2, itm);
  itm = new QTableWidgetItem(QString(target));
  ui->tableWidget->setItem(cnt - 1, 3, itm);
  ui->tableWidget->scrollToBottom();
  cnt++;

  towers->finished = 0;
  while(!towers->finished) {
  towers->animate(10 - n, source, target);
  QCoreApplication::processEvents();
  QThread::msleep((1100 - speed) / 100);
  }
  if (source == 'A') towers->minA += 20; else if (source == 'B') towers->minB += 20; else towers->minC += 20;

  QCoreApplication::processEvents();
  update();
  QThread::msleep(1100 - speed);
}

void MainWindow::on_pushButton_clicked()
{
  towers->isChanging = false;
  ui->pushButton->hide();
  ui->spinBox->hide();
  ui->label_2->setText(QString::number(N));
  ui->label_3->show();
  ui->label_4->show();

  towers->minA -= towers->posN[N - 1];
  towers->minB -= towers->posN[N - 1];
  towers->minC -= towers->posN[N - 1];

  hanoi(N, 'A', 'B', 'C');
}

void MainWindow::on_party_clicked()
{
  if (towers->party)
  towers->party = false;
  else
  towers->party = true;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
  N = arg1;
  towers->setN(arg1);
  QCoreApplication::processEvents();
  update();
}

void MainWindow::on_slider_valueChanged(int arg1)
{
  ui->label_6->setText(QString::number(speed));
  speed = arg1;
  update();
}
