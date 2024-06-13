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

int MainWindow::reverse(int n, int a = 0)
{
    if (n == 0) {
        return a;
    } else {
        return reverse(n / 10, 10 * a + n % 10);
    }
}

void MainWindow::on_inputSpinBox_valueChanged(int arg1)
{
    ui->inputNumLabel->setText(QString::number(arg1));
    ui->reverseNumLabel->setText(QString::number(reverse(arg1)));
}
