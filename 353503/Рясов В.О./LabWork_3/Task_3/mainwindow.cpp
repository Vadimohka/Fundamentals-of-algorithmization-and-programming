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

void MainWindow::on_pushButton_clicked()
{
    long long input = ui->lineEdit->text().toInt();
    ui->label->setText(QString::number(reverse(input)));
}

long long MainWindow::reverse(long long input, long long reversed)
{
    if(input == 0){
        return reversed;
    }

    int d = input % 10;

    return reverse(input/10, reversed*10 + d);
}

