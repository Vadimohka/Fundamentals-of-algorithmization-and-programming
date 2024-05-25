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

void Widget::on_show_answer_clicked() {
    QString line = ui->input_lineEdit->text();
    if (setNumber(line)) {
        size_t answer = findReverseNumber(_number);
        ui->output_lineEdit->setText(QString::number(answer));
    }
    else {
        ui->output_lineEdit->setText("Wrong input!");
    }
}

bool Widget::setNumber(QString line) {
    _number = line.toULongLong();
    if (_number == 0 && line[0] == "-" || _number == 0 && line[0] != "0") {
        return false;
    }
    else return true;
}

size_t Widget::findReverseNumber(size_t number1, size_t number2) {
    if (number1 == 0) {
        return number2;
    }
    else {
        return findReverseNumber(number1 / 10, number2 * 10 + number1 % 10);
    }
}

