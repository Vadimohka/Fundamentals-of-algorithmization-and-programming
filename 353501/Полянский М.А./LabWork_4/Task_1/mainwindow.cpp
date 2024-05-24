#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    array = new VisualVector(scene);
    time = new QElapsedTimer();
    array->SetSize(100);
    array->FillArray();
    array->Show();
    ui->reset->setEnabled(false);
    ui->frame->hide();
    
    
   
}

void MainWindow::on_arraysize_valueChanged(){
  array->SetSize(ui->arraysize->value());
  array->FillArray();
  array->Show();
}

void MainWindow::on_reset_clicked(){
  array->SetSize(100);
  array->FillArray();
  array->Show();
  ui->frame->hide();

}

void MainWindow::on_start_clicked(){
  
  ui->reset->setEnabled(false);
  time->restart();
  int ind = ui->comboBox->currentIndex();
  if(ind == 0){
    array->HeapSort();
    ui->lineEdit_2->setText("Time of sort:" + QString::number(time->elapsed()/60));
    
  }else if(ind == 1){
    array->QuickSort(0, array->GetSize()-1);
    ui->lineEdit_2->setText("Time of sort:" + QString::number(time->elapsed()/60));
  }else {
    array->MergeSort(0, array->GetSize() -1);
    ui->lineEdit_2->setText("Time of sort:" + QString::number(time->elapsed()/60));
  }
  ui->reset->setEnabled(true);
  ui->frame->show();
}
void MainWindow::on_find_clicked(){
  int num = array->BinSearch(ui->spinBox->value());
  if(num == -1){
    ui->lineEdit->setText("no elements in array");
  }else{
    ui->lineEdit->setText("Position:" + QString::number(num));
  }

}

