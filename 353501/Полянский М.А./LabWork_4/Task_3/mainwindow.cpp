#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);
  
 
}

void MainWindow::on_add_clicked(){
  allNumber.push_back(ui->number->value());
  ui->array->insertPlainText(QString::number(ui->number->value())+ " ");
}

void MainWindow::on_calculate_clicked(){
  median.clear();
  ui->mediane->clear();
  for (long  i = 0; i < allNumber.size(); i += 3)
  {
    int a = allNumber[i];
    int b = (i + 1 < allNumber.size()) ? allNumber[i + 1] : a; 
    int c = (i + 2 < allNumber.size()) ? allNumber[i + 2] : b; 
    
    int res = std::min(std::max(a, b), std::max(std::min(a, b), c));
    
    
    median.push_back(res);
    ui->mediane->insertPlainText(QString::number(median.back())+ " ");
  }
}

void MainWindow::on_randomadd_clicked(){
  for (long i =0; i< ui->random->value(); i++){
    allNumber.push_back(QRandomGenerator::global()->bounded(0, 100));
    ui->array->insertPlainText(QString::number(allNumber.back()) + " ");
  }

}

void MainWindow::on_reset_clicked(){
  allNumber.clear();
  median.clear();
  ui->array->clear();
  ui->mediane->clear();
  
}