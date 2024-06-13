#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow), bst(new VisualBST) {
  ui->setupUi(this);
  
  update();
}

void MainWindow::update(){
  bst->fillEntries(ui->tree);
  ui->totlen->setText(QString::number(bst->findTotalLen()));
}

void MainWindow::on_clearBtn_clicked(){
  bst->clear();
  update();
}

void MainWindow::on_randBtn_clicked(){
  bst->randomize();
  update();
}


void MainWindow::on_getBtn_clicked(){
  long k = ui->key->value();
  QString found = "not found";
  if(bst->findByKey(k)){
    found = bst->get(k);
  }
  ui->value->setText(found);
}

void MainWindow::on_setBtn_clicked(){
  long k = ui->key->value();
  QString data = ui->value->text();
  bst->insert(k, data);
  update();
}


void MainWindow::on_balanceBtn_clicked(){
  bst->balance();
  update();
}

void MainWindow::on_delBtn_clicked(){
  long key = ui->key->value();
  QString v = "not found";
  if(bst->findByKey(key)){
    v = bst->get(key);
  }
  ui->value->setText(v);
  bst->removeByKey(key);
  update();
}