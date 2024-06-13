#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->spinBox->setMaximum(Size-1);
  ui->label->setWordWrap(true);  
  updateSet();
}

void MainWindow::updateSet(){
  auto s = bits.to_string();
  QString cur;
  cur.reserve(s.size() * 1.125);
  for(int i=0; i< s.size(); ++i){
    cur.push_back(s[i]);
    if(i%16 == 15){
      cur.push_back('\t');
    }
  }
  ui->label->setText(cur);
  updateInfo();
}

void MainWindow::updateInfo(){
  ui->all->setText(bits.all() ? "true" : "false");
  ui->none->setText(bits.none() ? "true" : "false");
  ui->any->setText(QString::number(bits.count()));
  ui->size->setText(QString::number(bits.size())); 
  ui->ulong->setText(QString::number(bits.to_ullong()));
  ui->count->setText(QString::number(bits.count())); 

}

void  MainWindow::on_flip_clicked(){
  auto u = ui->spinBox->value();
  if(u== -1){
    bits.flip();
  }else{
    bits.flip(u);
  }
  updateSet();

}

void MainWindow::on_reset_clicked(){
  auto u  = ui->spinBox->value();
  if(u==-1){
    bits.reset();

  }else{
    bits.reset(u);
  }
  updateSet();

}

void MainWindow::on_test_clicked(){
  auto u = ui->spinBox->value();
  if(u == -1){
    QMessageBox::information(this, "Info", "Index is -1. No value tested.");
  } else {
    QMessageBox::information(this, "Info", 
    QString("Tested bit %1. The value is: %2").arg(u).arg(bits[u]));
  }
  updateSet();
}


void MainWindow::on_set_clicked(){
  auto u = ui->spinBox->value();
  if(u == -1){
    bits.set();
  }else{
    bits.set(u);
  }
  updateSet();
}