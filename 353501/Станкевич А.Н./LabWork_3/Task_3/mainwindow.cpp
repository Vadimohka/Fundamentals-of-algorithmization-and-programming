#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onSpinBoxValueChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::reverseNumber(int n, int reversed) {
    if (n == 0)
        return reversed;
    else
        return reverseNumber(n / 10, reversed * 10 + n % 10);
}

void MainWindow::onSpinBoxValueChanged(int value) {
    int reversed = reverseNumber(value, 0);
    ui->label_3->setText(QString::number(reversed));
}
