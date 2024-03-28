#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <climits>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->secondDblBox->setMaximum(1e100);
  ui->secondDblBox->setMinimum(-1e100);
  ui->secondIntBox->setMaximum(INT_MAX);
  ui->secondIntBox->setMinimum(INT_MIN);
  ui->firstIntBox->setMaximum(INT_MAX);
  ui->firstIntBox->setMinimum(INT_MIN);

  ui->firstTbl->setEditTriggers(QTableWidget::NoEditTriggers);
  ui->secondTbl->setEditTriggers(QTableWidget::NoEditTriggers);

  ui->firstTbl->setSelectionBehavior(QTableWidget::SelectRows);
  ui->firstTbl->setSelectionMode(QTableWidget::SingleSelection);
  ui->secondTbl->setSelectionBehavior(QTableWidget::SelectRows);
  ui->secondTbl->setSelectionMode(QTableWidget::SingleSelection);

  ui->firstTbl->setColumnCount(1);
  ui->secondTbl->setColumnCount(2);
}

void MainWindow::updateTable(int num, int beg, int end){
  if(num == 0){

    if(end > ui->firstTbl->rowCount()){
      ui->firstTbl->setRowCount(end);
    }
    for(int i = beg; i < end; ++i){
      ui->firstTbl->setItem(i, 0, new QTableWidgetItem(
        QString::number(matrix.first[i])));
    }
  } else if(num == 1){
    if(end > ui->secondTbl->rowCount()){
      ui->secondTbl->setRowCount(end);
    }
    for(int i = beg; i < end; ++i){
      ui->secondTbl->setItem(i, 0, new QTableWidgetItem(
        QString::number(matrix.second[i].first)));
        ui->secondTbl->setItem(i, 1, new QTableWidgetItem(
        QString::number(matrix.second[i].second)));
    }
  }
}

void MainWindow::on_firstPushBtn_clicked(){
  //qDebug() << "clicked";
  matrix.first.push_back(ui->firstIntBox->value());
  updateTable(0, matrix.first.size()-1, matrix.first.size());
}

void MainWindow::on_secondPushBtn_clicked(){
  matrix.second.emplace_back(ui->secondIntBox->value(), ui->secondDblBox->value());
  updateTable(1, matrix.second.size()-1, matrix.second.size());
}

void MainWindow::on_firstInsertBtn_clicked(){
  if(!ui->firstTbl->selectedItems().empty()){
    auto cur_row = ui->firstTbl->currentRow();
    matrix.first.emplace(cur_row, ui->firstIntBox->value());
    updateTable(0, cur_row, matrix.first.size());
  }
}

void MainWindow::on_secondInsertBtn_clicked(){
  if(!ui->secondTbl->selectedItems().empty()){
    auto cur_row = ui->secondTbl->currentRow();
    matrix.second.emplace(cur_row, ui->secondIntBox->value(), ui->secondDblBox->value());
    updateTable(1, cur_row, matrix.second.size());
  }
}

void MainWindow::on_popBackBtn_clicked(){
  if(ui->firstTbl->hasFocus()){
    if(matrix.first.size() == 0){
      return;
    }
    matrix.first.pop_back();
    ui->firstTbl->setRowCount(matrix.first.size());
    updateTable(0, matrix.first.size()-1, matrix.first.size());
  } else if (ui->secondTbl->hasFocus()){
    if(matrix.second.size() == 0){
      return;
    }
    matrix.second.pop_back();
    ui->secondTbl->setRowCount(matrix.second.size());
    updateTable(1, matrix.second.size()-1, matrix.second.size());
  }
}

void MainWindow::on_clearBtn_clicked(){

  if(ui->firstTbl->hasFocus()){
    matrix.first.clear();
    ui->firstTbl->setRowCount(0);
  } else if(ui->secondTbl->hasFocus()){
    matrix.second.clear();
    ui->secondTbl->setRowCount(0);
  }
}

void MainWindow::on_eraseBtn_clicked(){
  if(ui->secondTbl->hasFocus() && !ui->secondTbl->selectedItems().empty()){
    auto cur_row = ui->secondTbl->currentRow();
    matrix.second.erase(cur_row);
    ui->secondTbl->setRowCount(matrix.second.size());
    updateTable(1, cur_row, matrix.second.size());
  } else if (ui->firstTbl->hasFocus() && !ui->firstTbl->selectedItems().empty()){
    auto cur_row = ui->firstTbl->currentRow();
    matrix.first.erase(cur_row);
    ui->firstTbl->setRowCount(matrix.first.size());
    updateTable(0, cur_row, matrix.first.size());
  }
}