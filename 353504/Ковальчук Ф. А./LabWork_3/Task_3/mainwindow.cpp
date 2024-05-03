#include "mainwindow.h"
#include "ui_mainwindow.h"


unsigned long long Reverse(unsigned long long value, unsigned long long reversed = 0)
{
    if (value != 0)
    {
        unsigned long long digit = value % 10;
        return Reverse(value / 10, reversed * 10 + digit);
    }
    return reversed;
}


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
    unsigned long long value = ui->lineEdit->text().toULongLong();
    unsigned long long output = Reverse(value);
    ui->label_2->setText(QString::number(output));
}

