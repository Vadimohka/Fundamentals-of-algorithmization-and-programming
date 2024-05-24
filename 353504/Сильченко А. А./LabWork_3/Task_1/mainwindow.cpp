#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,7}([.][0-9]{1,9})?$"),this));
    QPalette p(ui->centralwidget->palette());
    p.setColor(QPalette::Window, QColor(179, 243, 235));
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(p);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::long_bin(long num) {
    if (num == 0)
        return "";
    return long_bin(num / 2) + QString::number(num % 2);
}

QString MainWindow::double_bin(double num, int n) {
    if (n == 0){
        return "0";
    }
    if (num * 2 == 1){
        return "1";
    }
    else if (num * 2 > 1){
        return "1" + double_bin(num * 2 - 1, n - 1);
    }
    else return "0" + double_bin(num * 2, n - 1);
}


QString MainWindow::fun(QString str) {
    double ld = str.toDouble();
    long pd = (long) ld;
    ld = ld - pd;
    if (ld != 0){
        return long_bin(pd) + "." + double_bin(ld, 52);
    }
    else {
        return long_bin(pd) +".0";
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui -> lineEdit -> text();
    if (str != ""){
        str = fun(str);
        ui -> label_2 -> setText("Результат: " + str);
    }
}
