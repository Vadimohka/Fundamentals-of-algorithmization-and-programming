#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ConstMainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(outputNumber()));
    timer->start(SPEED_TIMER);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Функция для преобразования целой части числа
QString MainWindow::decimalToBinaryInt(long long intNumber) {

    if (intNumber == 0)
    {
        return "0";
    }

    else if(intNumber == 1)
    {
        return "1";
    }

    return decimalToBinaryInt(intNumber / NUMBER_BINARY_SISTEM) + QString::number(intNumber % NUMBER_BINARY_SISTEM);
}

// Функция для преобразования дробной части числа
QString MainWindow::decimalToBinaryFraction(double fraction, short precision) {
    QString binaryFraction = ".";

    while (precision-- && fraction)
    {
        fraction *= NUMBER_BINARY_SISTEM;
        short bit = static_cast<short>(fraction);
        binaryFraction += QString::number(bit);
        fraction -= bit;
    }

    if(binaryFraction.size() == ONLY_DOT)
    {
        return "";
    }

    return binaryFraction;
}

// Объединяющая функция для преобразования вещественного числа
QString MainWindow::decimalToBinary(double number, short precision) {

    if (number == 0)
    {
        return "0";
    }

    long long intPart = static_cast<long long>(number);
    double fractionPart = number - intPart;

    return decimalToBinaryInt(intPart) + decimalToBinaryFraction(fractionPart, precision);
}

void MainWindow::outputNumber()
{
    QString inputNumber;

    if(inputNumber != ui->inputLineEdit->text())
    {

        inputNumber = ui->inputLineEdit->text();

        if(inputNumber.toDouble() || inputNumber == "0")
        {
            (inputNumber.toDouble() < 0)? ui->signBit->setText("1") : ui->signBit->setText("0");

            ui->answerLineEdit->setText(decimalToBinary(abs(inputNumber.toDouble()), ui->spinBoxPrecision->value()));
        }

        else
        {
            ui->signBit->setText("-");
            ui->answerLineEdit->setText("Incorreсt input");
        }

    }
}
