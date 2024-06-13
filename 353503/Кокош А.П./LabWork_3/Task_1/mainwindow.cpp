#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->inputSpinBox->setMaximum(1000000000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MyRecursion(int a)
{
    if (a > 1)
        MyRecursion(a / 2);
    a % 2 ? binaryNumber.append('1') : binaryNumber.append('0');
}

void MainWindow::MyRecursionDecimal(double a)
{
    a *= 2;
    if (a >= 1) {
        binaryNumber.append('1');
    } else {
        binaryNumber.append('0');
    }
    if (a == (int) a) {
        return;
        if (a >= 1) {
            binaryNumber.append('1');
        } else {
            binaryNumber.append('0');
        }
    }
    MyRecursionDecimal(a - (int) a);
}

void MainWindow::on_pushButton_clicked()
{
    ui->outputLabel->clear();
    MyRecursion(ui->inputSpinBox->value());
    if (ui->inputSpinBox->value() != (int) ui->inputSpinBox->value()) {
        binaryNumber.append(',');
        MyRecursionDecimal(ui->inputSpinBox->value() - (int) ui->inputSpinBox->value());
    }
    ui->outputLabel->setText(binaryNumber);
    binaryNumber.clear();
}
