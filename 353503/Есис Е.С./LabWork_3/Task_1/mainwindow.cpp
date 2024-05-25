#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bitset>
//#include "binary.h"

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

QString MainWindow::decimalToBinary(double number)
{
    int integerPart = int(number);
    double decimalPart = number - integerPart;

    QString binaryIntegerPart = QString::number(integerPart, 2);
    QString binaryDecimalPart = decimalPartToBinary(decimalPart);

    return binaryIntegerPart + "." + binaryDecimalPart;
}

QString MainWindow::decimalPartToBinary(double decimalPart)
{
    QString binaryDecimalPart;
    while (decimalPart != 0.0)
    {
        decimalPart *= 2;
        int bit = int(decimalPart);
        decimalPart -= bit;
        binaryDecimalPart.append(QString::number(bit));
    }
    return binaryDecimalPart;
}


void MainWindow::on_lineEdit_textChanged()
{
    double number = ui->lineEdit->text().toDouble();
    QString binary = decimalToBinary(number);
    ui->textEdit->setText(binary);
}

