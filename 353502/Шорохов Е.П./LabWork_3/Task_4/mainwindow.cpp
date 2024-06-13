#include "mainwindow.h"
#include "./ui_mainwindow.h"

//I am booored
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
    int8_t value = ui->textEdit->toPlainText().toInt();
    ui->textEdit_2->setPlainText(QString::number(Algorithms::Hanoi(0, 2, value)));
}

