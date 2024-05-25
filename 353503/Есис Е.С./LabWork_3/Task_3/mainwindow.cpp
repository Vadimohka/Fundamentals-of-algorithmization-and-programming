#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QCoreApplication>

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

int MainWindow::Recurse(int n, int reversed) {
    // Базовый случай: если число состоит из одной цифры
    if (n < 10) {
        return reversed * 10 + n;
    }

    // Получаем последнюю цифру числа
    int lastDigit = n % 10;

    // Убираем последнюю цифру из числа
    int remainingNumber = n / 10;

    // Рекурсивно вызываем функцию для оставшейся части числа
    return Recurse(remainingNumber, reversed * 10 + lastDigit);
}

void MainWindow::on_pushButton_clicked()
{ int n =  ui->number->text().toInt();
    ui->textEdit->setText(QString::number( Recurse(n,0)));
}

