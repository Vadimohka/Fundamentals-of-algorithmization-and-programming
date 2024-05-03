#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QString>
#include <string>

MainWindow::MainWindow(): ui(new Ui::MainWindow), timer(new QTimer(this)) {
    decimal = fraction = 0;
    ok = true;
    ui->setupUi(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, this, &MainWindow::calculate);
    ui->lineEdit->setMaxLength(11);
}

MainWindow::~MainWindow() {

}

void MainWindow::calculate() {

    decimal = (long long)ui->lineEdit->text().toDouble(&ok);
    // qDebug() << decimal;
    fraction = static_cast<long double>(abs(ui->lineEdit->text().toDouble(&ok) - decimal));
    // qDebug() << abs(ui->lineEdit->text().toDouble(&ok) - decimal);
    if (ok)
        ui->binary->setText(QString::fromStdString(DecimalToBinary(decimal) + FractionToBinary(fraction, 10)));
    else
        ui->binary->setText("0");
}

std::string MainWindow::DecimalToBinary(int n) {
    if (n < 0) {
        n *= -1;
        return "-" + DecimalToBinary(n);
    }
    if (n / 2 != 0) {
        return DecimalToBinary(n / 2) + std::to_string(n % 2);
    }
    return std::to_string(n % 2);
}

std::string MainWindow::FractionToBinary(double fraction, int precision) {
    std::string binaryFraction = ".";
    while (precision--) {
        fraction *= 2;
        int bit = fraction;
        if (bit == 1) {
            fraction -= bit;
            binaryFraction += '1';
        } else {
            binaryFraction += '0';
        }
    }
    return binaryFraction;
}
