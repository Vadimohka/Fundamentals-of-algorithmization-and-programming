#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<Airport.h>

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

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "fetfe";
    Airport *changi = new Airport;
    changi->id = ui->spinBox->value();
    for(int i{}; i < TEN; ++i){
        changi->flights[i]= ui->spinBox_2->value() + i * i ;
    }
    changi->isOpen = ui->checkBox->isChecked();
    strncpy(Airport::name, ui->lineEdit->text().toStdString().c_str(), sizeof(Airport::name) - 1);
    qDebug() << changi->printInfo();

    delete changi;
}

