#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qlineedit.h>
#include <qpushbutton.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
  
    connect(ui->convertButton, &QPushButton::pressed, this, &MainWindow::displayBinary);
}

void MainWindow::displayBinary(){
    double value = (ui->inputLineEdit->text()).toDouble();
    BinaryConverter binary(value);

    QString sign = binary.getSign();
    QString exponent = binary.getExponent();
    QString mantissa = binary.getMantissa();
    QString full = binary.getBinary();

    ui->signLineEdit->setText(sign);
    ui->exponentLineEdit->setText(exponent);
    ui->mantissaLineEdit->setText(mantissa);
    ui->fullBinaryLineEdit->setText(full);
}