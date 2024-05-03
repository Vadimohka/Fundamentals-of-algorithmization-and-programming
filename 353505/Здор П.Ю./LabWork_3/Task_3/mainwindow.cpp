#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox_2->setReadOnly(true);
    ui->spinBox->setMaximum(1e18);
    ui->spinBox->setMinimum(-1e18);
    ui->spinBox_2->setMaximum(1e18);
    ui->spinBox_2->setMinimum(-1e18);
    ui->spinBox_2->clear();
    ui->spinBox->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if(arg1!=0){
    int k= a.reverse(arg1);

    ui->spinBox_2->setValue(k);
    }
    else {
        ui->spinBox_2->clear();
    }
}

