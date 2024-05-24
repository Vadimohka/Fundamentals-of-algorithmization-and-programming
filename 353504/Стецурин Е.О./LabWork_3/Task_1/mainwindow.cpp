#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setMaximum(999999999);
    ui->doubleSpinBox->setDecimals(6);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString decimalToBinary(int n) {
    if (n / 2 != 0) {
        return decimalToBinary(n / 2) + QString::number(n % 2);
    }
    return QString::number(n);
}

QString fractionToBinary(double fraction, int precision=30) {
    QString binaryFraction;
    while (precision--) {
        fraction *= 2;
        int bit = static_cast<int>(fraction);
        if (bit == 1) {
            fraction -= bit;
            binaryFraction.append("1");
        } else {
            binaryFraction.append("0");
        }
    }
    return binaryFraction;
}

void MainWindow::on_doubleSpinBox_valueChanged(double number)
{
    int integerPart = static_cast<int>(number);
    double fractionPart = number - integerPart;
    QString binaryInteger = decimalToBinary(integerPart);
    QString binaryFraction = fractionToBinary(fractionPart);
    binaryFraction.remove(QRegularExpression("0+$"));
    if (binaryFraction==""){
        ui->label->setText(binaryInteger);
    }else{
        ui->label->setText(binaryInteger + "." + binaryFraction);
    }
}


