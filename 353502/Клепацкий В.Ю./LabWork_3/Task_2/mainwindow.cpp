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

int MainWindow::otvet(int m, int n)
{
    int z;
    if (m == 0) {
        return (z = n + 1); //z = n + 1; //return (z*=n+1);
    } else if (m > 0, n == 0) {
        return z = otvet(m - 1, 1);
    } else if (m > 0, n > 0) {
        return z = otvet(m - 1, otvet(m, n - 1));
    }
    //return z;
}

void MainWindow::on_pushButton_clicked()
{
    QString z;
    n1 = ui->lineN->text();
    m1 = ui->lineM->text();
    n = n1.toInt();
    m = m1.toInt();
    z = QString::number(otvet(m, n));
    ui->label_otvet->setText(z);
}
