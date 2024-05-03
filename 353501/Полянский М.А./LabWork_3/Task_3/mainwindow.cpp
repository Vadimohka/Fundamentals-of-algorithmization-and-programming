#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::print);
  ui->lineEdit->setValidator(new CustomValidator());
}

void MainWindow::print(){
  bool ok;
  unsigned long long num = ui->lineEdit->text().toLong(&ok);
  unsigned long long result = solve(num, 0);
  ui->result->setText(QString::number(result));

    
}


long long MainWindow::solve(unsigned long long n,unsigned long long res){
  if(n == 0) return res;
  res *=10;
  res+=n%10;
  n/=10;
  return solve(n, res);
}