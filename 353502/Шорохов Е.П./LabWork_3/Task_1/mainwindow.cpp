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
    ui->textEdit->setPlainText(Parser::DtoS(ui->textEdit_2->toPlainText().toDouble()));
}

