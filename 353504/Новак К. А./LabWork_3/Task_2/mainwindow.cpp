#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mSpinBox->setMaximum(3);
    ui->nSpinBox->setMaximum(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::ackermann(int m, int n) {


    int result;
    if (m == 0) {
        result = n + 1;
    } else if (n == 0) {
        result = ackermann(m - 1, 1);
    } else {
        result = ackermann(m - 1, ackermann(m, n - 1));
    }


    return result;
}

void MainWindow::on_calculateButton_clicked()
{
    int m = ui->mSpinBox->value();
    int n = ui->nSpinBox->value();


    int result = ackermann(m, n);
    qDebug() << "Ackermann(" << m << ", " << n << ") = " << result;

    ui->resultLabel->setText(QString::number(result));
}
