#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

long long A(unsigned long long m, unsigned long long n)
{
    if(m == 0) return n + 1;
    else if(m > 0 && n == 0) return A(m - 1, 1);
    else if(m > 0 && n > 0) return A(m - 1, A(m, n - 1));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText(QString::number(A(ui->spinBox->value(), ui->spinBox_2->value())));
}

