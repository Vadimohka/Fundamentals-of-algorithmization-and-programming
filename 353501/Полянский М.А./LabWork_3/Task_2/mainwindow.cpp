#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  
 
  connect(ui->spinBox, &QSpinBox::valueChanged,this, &MainWindow::setMax);
  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::showRes);
}

void MainWindow::setMax(){
  int n = ui->spinBox->value();
  if(n == 1){
    ui->spinBox_2->setMaximum(100000);
  }else if( n ==2 ){
    ui->spinBox_2->setMaximum(20000);
  }else{
    ui->spinBox_2->setMaximum(9);
  }
}

void MainWindow::showRes(){
  int m = ui->spinBox->value();
  int n = ui->spinBox_2->value();
  int res = ackerman(m, n);
  ui->label_4->setText(QString::number(res));
}

int MainWindow::ackerman(int m, int n){
  if(m ==0) return n+1;
  else if(m> 0 && n==0) return  ackerman(m-1, 1);

  return ackerman(m-1, ackerman(m, n-1));
}

