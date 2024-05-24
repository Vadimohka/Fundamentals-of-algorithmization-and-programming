#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setFirstNumber(QString firstString) {
    _firstNumber = firstString.toULongLong();
    if (_firstNumber == 0 && firstString[0] == "-") {
        ui->firstNumber_lineEdit->setText("It's negative number!");
    }
    else if (_firstNumber == 0 && firstString[0] != "0") {
        ui->firstNumber_lineEdit->setText("Too big number!");
    }
}

void Widget::setSecondNumber(QString secondString) {
    _secondNumber = secondString.toULongLong();
    if (_secondNumber == 0 && secondString[0] == "-") {
        ui->secondNumber_lineEdit->setText("It's negative number!");
    }
    else if (_secondNumber == 0 && secondString[0] != "0") {
        ui->secondNumber_lineEdit->setText("Too big number!");
    }
}

void Widget::on_calculate_clicked() {
    QString firstString = ui->firstNumber_lineEdit->text();
    QString secondString = ui->secondNumber_lineEdit->text();
    setFirstNumber(firstString);
    setSecondNumber(secondString);
    unsigned long long result = functionOfAccerman(_firstNumber, _secondNumber);
    ui->output_lineEdit->setText(QString::number(result));
}

unsigned  long long Widget::functionOfAccerman(unsigned long long int m, unsigned long long int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (m > 0 && n == 0) {
        return functionOfAccerman(m - 1, 1);
    }
    else {
        return functionOfAccerman(m - 1, functionOfAccerman(m, n - 1));
    }
}

