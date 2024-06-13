#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::lineEdit_userTextChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lineEdit_userTextChanged(const QString &text)
{

    if (text.isEmpty()) {
        ui->label->clear();
        return;
    }

    isNegative = text.startsWith('-');
    QString newText = isNegative ? text.mid(1) : text;

    if (newText.isEmpty()) {
        ui->label->clear();
        return;
    }

    bool ok = true;
    double number = newText.toDouble(&ok);
    if (ok) {
        number = qAbs(number);
        QString result = ToBinary(number);

        ui->label->setText(result);

    }
    else {
        QMessageBox::critical(this, "Ошибка", "Некорректное значение!");
    }

}

QString MainWindow::integerToBinary(qint64 num) {
    if (num == 0) {
        return "";
    }
    QString binary = integerToBinary(num / 2);
    return binary + QString::number(num % 2);
}

QString MainWindow::fractionalToBinary(float num, qint64 precision) {
    if (precision <= 0) {
        return "";
    }

    QString binary;
    while (precision > 0) {
        num *= 2;
        qint64 bit = static_cast<qint64>(num);
        binary += QString::number(bit);
        num -= bit;
        precision--;
    }

    return binary;
}

QString MainWindow::ToBinary(double num) {
    if (num == std::floor(num)) {
        if (isNegative) {
            return "-" + integerToBinary(static_cast<qint64>(num));
        }
        return integerToBinary(static_cast<qint64>(num));
    }
    if (num == 0) {
        return "0";
    }

    QString binary;
    if (isNegative) {
        binary = "1 ";
    } else {
        binary = "0 ";
    }

    qint64 wholePart = std::floor(num);
    double fractionalPart = num - wholePart;

    QString wholeBinary = (wholePart != 0) ? integerToBinary(wholePart) : "0";
    QString fractionalBinary = (fractionalPart != 0) ? fractionalToBinary(fractionalPart, 23) : "";

    qint64 exponent = 127 + wholeBinary.length() - 1;
    QString exponentBinary = integerToBinary(exponent);

    // Если экспонента меньше 8 до добавляем нулей
    while (exponentBinary.length() < 8) {
        exponentBinary = "0" + exponentBinary;
    }

    // Construct the final binary string
    binary += exponentBinary + " ";
    binary += wholeBinary.mid(1) + fractionalBinary;
    // Если мантисса меньше 23 (то есть вся наша меньше 32) то добавляем нулей
    while (binary.length() < 32) {
        binary += "0";
    }

    return binary.left(34);
}
