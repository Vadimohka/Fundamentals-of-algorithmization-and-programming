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


long long MainWindow::reverse(long long n, long long r = 0) {
    if (n == 0)
        return r;
    else
        return reverse(n / 10, r * 10 + n % 10);
}

void MainWindow::on_pushButton_clicked()
{
    ui->number->clear();

    long long n;
    bool isOk;
    QString line = ui->lineEdit->text();

    n = line.toLongLong(&isOk);

    if (isOk) {
        ui->number->setText(QString::number(reverse(n)));
    } else {
        QMessageBox::critical(0, "Ошибка", "Неверный ввод или число слишком большое!\nВведите целое число!");
    }
}

