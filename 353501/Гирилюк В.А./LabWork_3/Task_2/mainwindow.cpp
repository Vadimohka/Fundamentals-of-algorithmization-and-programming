#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonResult_clicked()
{
    int m = ui->spinBoxM->value();
    int n = ui->spinBoxN->value();
    ui->outPutResult->setText(QString::number(ackermannFunction(m , n)));
}

int MainWindow::ackermannFunction(int m, int n)
{

    if(m == 0){
        return n + 1;
    }
    else if(m > 0 && n == 0){
        return ackermannFunction(m - 1, 1);
    }
    else if(m > 0 && n > 0){
        return ackermannFunction(m - 1, ackermannFunction(m, n - 1));
    }
}


void MainWindow::on_spinBoxM_valueChanged(int arg1)
{
    switch (arg1){
    case 0:
        ui->spinBoxN->setMaximum(INT_MAX);
        break;
    case 1:
        ui->spinBoxN->setMaximum(130900);
        break;
    case 2:
        ui->spinBoxN->setMaximum(3000);
        break;
    case 3:
        ui->spinBoxN->setMaximum(10);
        break;
    }
}

