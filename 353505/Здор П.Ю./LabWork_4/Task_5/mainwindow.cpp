#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(QString::number(1)+QString::number(2)+QString::number(3)+QString::number(4));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    size_t *c= a.at_m(2);
}


void MainWindow::on_pushButton_2_clicked()
{
    a.resize(3);
}


void MainWindow::on_pushButton_3_clicked()
{
    a.resize(5);
}


void MainWindow::on_pushButton_4_clicked()
{
    a.erase(2);
}


void MainWindow::on_pushButton_5_clicked()
{
    //a.reserve();
}

