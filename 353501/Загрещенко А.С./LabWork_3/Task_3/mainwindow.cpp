#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "longlongval.h"
#include <QTimer>


MainWindow::MainWindow(): ui(new Ui::MainWindow), timer(new QTimer(this)) {
  number = 0;
  ui->setupUi(this);
  timer->start(500);
  ui->lineEdit->setMaxLength(9);
  
  connect(timer, &QTimer::timeout, this, &MainWindow::calculate);
}

MainWindow::~MainWindow() {
  
}

void MainWindow::calculate() {
  number = ui->lineEdit->text().toLongLong();
  QString plus = (number < 0) ? "-" : " ";
  QString ans = QString::number(reverse(abs(number), 0)) + plus;
  ui->binary->setText(ans);
}

int MainWindow::reverse(int n, int a = 0) {
    if (n == 0) {
      return a;
    }
     else {
      return reverse(n / 10, 10 * a + n % 10);
    }
}

