#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

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

long long MainWindow::reverse(long long n)
{
    if(n == 0)
    {
        return _answer;
    }
    else
    {
        _answer = _answer * 10 + n % 10;
        return reverse(n /= 10);
    }
}

void MainWindow::on_reverseButton_clicked()
{
    _answer = 0;
    long long n = ui -> spinBox -> value();
    ui -> lineEdit -> setText(QString::number(reverse(n)));
}

