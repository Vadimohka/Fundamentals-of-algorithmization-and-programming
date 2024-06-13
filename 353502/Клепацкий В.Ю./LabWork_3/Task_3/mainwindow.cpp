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

int MainWindow::otvet(int n, int rev)
{
    if (n == 0)
        return rev;
    return otvet(n / 10, rev * 10 + n % 10);
}
void MainWindow::on_pushButton_clicked()
{
    QString reverse, chislo = ui->lineEdit->text();
    reverse = QString::number(otvet(chislo.toInt()));
    ui->label_otvet->setText(reverse);
}
