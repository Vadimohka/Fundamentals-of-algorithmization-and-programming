#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextEdit>


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

long long int MainWindow::ackermann(int m, int n)
{
    if (m == 0) {
        qDebug()<<"step 1";
        return n + 1;
    } else if (n == 0) {
        qDebug()<<"step 2";
        return ackermann(m - 1, 1);
    } else {
        qDebug()<<"step 3";
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}


void MainWindow::on_pushButton_clicked()
{
    int m = ui->textEdit->toPlainText().toInt();
    int n = ui->textEdit_2->toPlainText().toInt();
   if (m > 4 || (m == 3 && n >= 11) || (m == 4 && n >= 1)) {
        ui->textEdit_3->setText("Слишком большое число. Введите заново");
    }
   else{
     long long int result = ackermann(m, n);
    ui->textEdit_3->setText(QString::number(result));
    }
}



