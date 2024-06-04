#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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
     int n = ui->textEdit->toPlainText().toInt();
    int reversedNumber = r.reverseNumber(n);
     ui->textEdit_2->setText(QString::number(reversedNumber));

}

