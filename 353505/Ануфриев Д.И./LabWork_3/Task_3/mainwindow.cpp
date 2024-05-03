#include "mainwindow.h"
#include "ui_mainwindow.h"

long long reverse(long long a, int iteration)
{
    if(a == 0) return 0;
    if(a < 0)
    {
        return (-(a % 10) * pow(10, iteration) + reverse(-a / 10, floor(iteration - 1)));
    }
    else return ((a % 10) * pow(10, iteration) + reverse(a / 10, floor(iteration - 1)));

}

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
    ui->lineEdit->setText(QString::number(reverse(ui->spinBox->value(), log10(ui->spinBox->value()))));
}

