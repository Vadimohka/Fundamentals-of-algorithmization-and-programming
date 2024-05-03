#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QString>
#include <string>
#include <QTimer>

MainWindow::MainWindow(): ui(new Ui::MainWindow), timer(new QTimer()) {
  numberM = numberN = 0;
  timer->start(100);
  connect(timer, &QTimer::timeout, this, &MainWindow::change);
  ui->setupUi(this);
  ui->frame->setStyleSheet("background-image: url(/home/konstantin/Рабочий стол/Compurer science/Lab3/Task_2/task.png); background-position: right bottom;");
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow() {
  
}

void MainWindow::change() {
  if (ui->spinBox_numberM->text().toULongLong() == 0) ui->spinBox_numberN->setMaximum(INT_MAX); else
  if (ui->spinBox_numberM->text().toULongLong() == 1) ui->spinBox_numberN->setMaximum(130880); else
  if (ui->spinBox_numberM->text().toULongLong() == 2) ui->spinBox_numberN->setMaximum(2048); else
  if (ui->spinBox_numberM->text().toULongLong() == 3) ui->spinBox_numberN->setMaximum(9); else ui->spinBox_numberM->setMaximum(0);
}

void MainWindow::on_pushButton_clicked() {
  numberM = ui->spinBox_numberM->text().toULongLong();
  numberN = ui->spinBox_numberN->text().toULongLong();
  ui->binary->setText(QString::number(funk(numberM, numberN)));
}

unsigned long long MainWindow::funk(long long m, long long n) {
  if (m == 0) return n + 1; else
  if (m > 0 && n == 0) return funk(m - 1, 1); else
  if (m > 0 && n > 0) return funk(m - 1, funk(m, n - 1));
}
