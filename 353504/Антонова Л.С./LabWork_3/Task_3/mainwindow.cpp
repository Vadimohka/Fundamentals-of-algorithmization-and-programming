#include "mainwindow.h"
#include "ui_mainwindow.h"

long long MainWindow::Reverse(long long num, long long k)
{
    if (num == 0) return k;
    return Reverse(num / 10, k * 10 + num % 10);
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
    long long x = 0;

    QString s = ui->textEdit->toPlainText();
    x = s.toLongLong();

    x = Reverse(x, 0);
    ui->label_2->setText("Result: " + QString::number(x));
}
