#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    int num = ui->spinBox->value();
    int reversed = 0;
    int result = func::recurs(num, reversed);
    ui->textBrowser->setText(QString::number(result));
}
