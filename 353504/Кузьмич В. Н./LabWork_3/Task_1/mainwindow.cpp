#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::long_fun(long num) {
    if (num == 0)
        return "";
    return long_fun(num / 2) + QString::number(num % 2);
}

QString MainWindow::double_fun(double num, int n) {
    if (n == 0){
        return "";
    }
    if (num * 2 == 1){
        return "1";
    }
    else if (num * 2 > 1){
        return "1" + double_fun(num * 2 - 1, n - 1);
    }
    else return "0" + double_fun(num * 2, n - 1);
}


QString MainWindow::fun(QString str) {
    double ld = str.toDouble();
    long pd = (long) ld;
    ld = ld - pd;
    if (ld != 0){
        return long_fun(pd) + "." + double_fun(ld, 52);
    }
    else {
        return long_fun(pd) +".0";
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,7}([.][0-9]{1,9})?$"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui -> lineEdit -> text();
    if (str != ""){
        str = fun(str);
        ui -> label_2 -> setText("Результат: " + str);
    }
}

