#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    BinaryOperation answer(new Number(3),'-', new BinaryOperation(new Number(9), '/', new Number(-80.2)));
    double ans = answer.count();
    ui->lineEdit->setText(QString::number(ans));
}

MainWindow::~MainWindow()
{
    delete ui;
}
