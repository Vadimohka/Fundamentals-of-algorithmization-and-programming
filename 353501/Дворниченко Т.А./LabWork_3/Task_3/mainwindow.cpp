#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->HOHOHO, &QPushButton::clicked, this, &MainWindow::on_HOHOHO_clicked);

}
uint_least64_t reverseNumber(int n,int reversed = 0)
{
    if (n == 0)
        return reversed;

    int lastDigit = n % 10;
    int remaining = n / 10;
    reversed = (reversed * 10) + lastDigit;

    return reverseNumber(remaining, reversed);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_HOHOHO_clicked()
{
    int m = ui->Kryto->text().toInt();


    uint_least64_t result = reverseNumber(m);

    ui->label->setText("Результат: " + QString::number(result));

}

