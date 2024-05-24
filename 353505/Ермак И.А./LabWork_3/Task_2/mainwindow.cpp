#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setPlainText("1");
    ui->textEdit->setReadOnly(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::AkeraMAN(int m, int n) {

    if (m == 0) {
        return n + 1;
    }
    if (m > 0 && n == 0) {
        return AkeraMAN(m - 1, 1);
    }
    if (m > 0 && n > 0) {
        return AkeraMAN(m - 1, AkeraMAN(m, n - 1));
    }
}

void MainWindow::on_spinBox_N_valueChanged(int arg1)
{
    N = arg1;
    if (M == 3) {
        ui->spinBox_N->setMaximum(11);

    }
    else {
        ui->spinBox_N->setMaximum(1000);
       // ui->spinBox_M->setMaximum(11);
    }
    ui->textEdit->setPlainText(QString::number(AkeraMAN(M, N)));
}


void MainWindow::on_spinBox_M_valueChanged(int arg1)
{
    M = arg1;
    if (N > 11) {
        ui->spinBox_M->setMaximum(2);


    }
    else {
        ui->spinBox_M->setMaximum(3);
        ui->spinBox_N->setMaximum(1000);
    }
    ui->textEdit->setPlainText(QString::number(AkeraMAN(M, N)));
}

