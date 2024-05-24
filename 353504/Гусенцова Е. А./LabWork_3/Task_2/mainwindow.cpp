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

void MainWindow::on_pushButton_clicked()
{
    int m = ui->mVariant->value();
    int n = ui->nVariant->value();

    if (m >5 && n==0)
    {
        QMessageBox::information(this, tr("Warning!"), tr(" m is too big. The m value shouldn't exceed 5, when n is equal to 0 "), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    if (m >4 && n!=0)
    {
        QMessageBox::information(this, tr("Warning!"), tr(" m is too big. The m value shouldn't exceed 4 "), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    if (m == 3 && n>=14)
    {
        QMessageBox::information(this, tr("Warning!"), tr(" When m=3, the n value shouldn't exceed 13 "), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int output = func::recurs(m, n);
    ui->Output->setText(QString::number(output));
}
