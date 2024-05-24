#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::reverseNumber);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reverseNumber()
{
    int n = ui->numberSpinBox->value();
    int reversedN = recursiveReverse(n, 0);
    ui->resultLabel->setText(QString::number(reversedN));
}

int MainWindow::recursiveReverse(int n, int reversedN)
{
    if (n == 0)
        return reversedN;
    else
        return recursiveReverse(n / 10, reversedN * 10 + n % 10);
}
