#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <qmessagebox.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->indexSbox->setMaximum(bsetSize-1);
  ui->bitsetLbl->setWordWrap(true);
  updateBitset();
}

void MainWindow::on_flipBtn_clicked(){
   auto i = ui->indexSbox->value();
   if(i == -1){
    bitset.flip();
   } else{
    bitset.flip(i);
   }
   updateBitset();
}

void MainWindow::on_resetBtn_clicked(){
   auto i = ui->indexSbox->value();
  if(i == -1){
    bitset.reset();
  } else {
    bitset.reset(i);
  }
  updateBitset();
}
void MainWindow::on_testBtn_clicked(){
  auto i = ui->indexSbox->value();
  if(i == -1){
    QMessageBox::information(this, "Info", "Index is -1. No value tested.");
  } else {
    QMessageBox::information(this, "Info", 
    QString("Tested bit %1. The value is: %2").arg(i).arg(bitset[i]));
  }

  updateBitset();
}

void MainWindow::on_setBtn_clicked(){
   auto i = ui->indexSbox->value();
   if(i == -1){
    bitset.set();
   } else {
    bitset.set(i);
   }
   updateBitset();

}
void MainWindow::MainWindow::updateBitset() {
  auto s = bitset.to_string();
  QString ls;
  ls.reserve(s.size() * 1.125);
  for(int i = 0; i < s.size(); ++i){
    ls.push_back(s[i]);
    if(i % 16 == 15){
      ls.push_back('\n');
    }
  }

  ui->bitsetLbl->setText(ls);
  update_info();  
}

void MainWindow::MainWindow::update_info() {
  ui->allLbl->setText(bstr(bitset.all()));
  ui->noneLbl->setText(bstr(bitset.none()));
  ui->anyLbl->setText(bstr(bitset.any()));
  ui->countLbl->setText(QString::number(bitset.count()));
  ui->toullongLbl->setText(QString::number(bitset.to_ullong()));
  ui->sizeLbl->setText(QString::number(bitset.size()));
}

QString MainWindow::MainWindow::bstr(bool b) {
  return b ? "true" : "false";    
}
