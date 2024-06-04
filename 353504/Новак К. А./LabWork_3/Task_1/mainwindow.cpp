
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QString windowStyle = "background-color: #4A5859;";
    this->setStyleSheet(windowStyle);

    // Установка стилей для кнопок
    QString buttonStyle = "QPushButton {"
                          "background-color: #F4B860;"


                          "color: #32373B;"
                          "font-size: 15px;"

                          "}"
                          "QPushButton:hover {"
                          "background-color: #558C8C;"
                          "color: #E8DB7D;"
                          "}"
        ;

    ui->convertButton->setStyleSheet(buttonStyle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::integerToBinary(int integer) {
    if (integer == 0)
        return "0";
    else if (integer == 1)
        return "1";
    else
        return integerToBinary(integer / 2) + QString::number(integer % 2);
}

QString MainWindow::fractionToBinary(double fraction, int precision) {
    if (precision == 0)
        return "";

    fraction *= 2;
    int bit = fraction;

    return QString::number(bit) + fractionToBinary(fraction - bit, precision - 1);
}

QString MainWindow::decimalToBinary(double num, int precision) {
    QString binary = integerToBinary(static_cast<int>(num)); // Преобразуем целую часть

    if (num != static_cast<int>(num)) {
        binary += '.';
        binary += fractionToBinary(num - static_cast<int>(num), precision);
    }

    return binary;
}

void MainWindow::on_convertButton_clicked()
{
    double number = ui->inputLineEdit->text().toDouble();
    int precision = ui->precisionSpinBox->value();

    QString binary = decimalToBinary(number, precision);
    ui->textEdit->setText("Двоичное представление: " + binary);
}
