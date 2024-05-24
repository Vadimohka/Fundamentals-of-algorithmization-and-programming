#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

long long Akkerman(int m, int n)
{
    qDebug() << m << n;
    if (m == 0) return n + 1;
    if (m > 0 && n == 0) return Akkerman(m - 1, 1);
    return Akkerman(m - 1, Akkerman(m, n - 1));
}

void MainWindow::on_pushButton_clicked()
{
    int m = ui->spinBox->value();
    int n = ui->spinBox_2->value();

    if (m > 4 || (m == 4 && n) || (m == 3 && n > 10) || (m == 2 && n > 10000) || (m == 1 && n > 261114))
    {
        QMessageBox::information(this, tr("Инфо"), tr("Введёные числа получат огромное число!"), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    ui->label->setText(QString::number(Akkerman(m, n)));
}

