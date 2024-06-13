#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

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

void MainWindow::on_pushButton_2_clicked()
{
    QString input = ui->lineEdit->text();
    int m = input.toInt();
    input = ui->lineEdit_2->text();
    int n = input.toInt();
    if(m >=4 or n >=13 and m == 3 or n > 18000 ){
        QMessageBox::warning(this, "Warning", "Переполнение стека.");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        return;
    }
    ackerman(m, n);
    ui->label->setText(QString::number(ackerman(m,n)));
}

int MainWindow::ackerman(int m, int n)
{
    if(m == 0){
        return n + 1;
    }

    else if (m > 0 and n == 0){
        return ackerman(m - 1, 1);
    }
    else if (m > 0 and n > 0){
        return ackerman(m - 1, ackerman(m, n - 1));
    }
}

