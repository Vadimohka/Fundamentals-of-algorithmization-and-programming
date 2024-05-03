#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <QDebug>

QString strf,strw;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    label = new QLabel;
    setWindowTitle("Перевод числа из десятичной в двоичную систему");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    fraction(arg1-floor(arg1));
    wholep(int(floor(arg1)));
    std::reverse(strw.begin(),strw.end());
    strw.append(",");
    if(strf == "")
        strf = "0";
    strw.append(strf);

    ui->label->setText(strw);
    strw = "";
    strf = "";
}

void MainWindow::fraction(double value)
{
    value = (value - floor(value))*2;
    if(value == 0 || strf.size() == 52)
        return;
    qDebug() << QString::number(floor(value));
    strf.append(QString::number(floor(value)));
    fraction(value);
}

void MainWindow::wholep(int value){
    qDebug() << QString::number(value%2);
    strw.append(QString::number(value%2));
    value = value/2;
    if(value !=0)
        wholep(value);
    return;
}
