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

double Widget::getNumber2() {
    return _number2;
}

void Widget::on_getAnswer_clicked() {
    ui->output_lineEdit->setText("");
    QString line = ui->input_lineEdit->text();
    if (setNumber10(line)) {
        line = from10To2(_number10);
        ui->output_lineEdit->setText(line);
    }
}

bool Widget::setNumber10(QString number10) {
    _number10 = number10.toDouble();
    if (_number10 == 0 && number10[0] != "0") {
        ui->input_lineEdit->setText("Wrong input!");
        return false;
    }
    else return true;
}

QString Widget::from10To2(double number10) {
    int decimal = number10;
    double undecimal = number10 - decimal;
    QString decimalString, undecimalString;
    decimalString = decimalTo2(decimal, "");
    std::reverse(decimalString.begin(), decimalString.end());
    undecimalString = undecimalTo2(undecimal, 0, 0);
    return decimalString + ',' + undecimalString;
}

QString Widget::decimalTo2(int decimal, QString answer) {
    if (decimal >= 1) {
        answer += QString::number(decimal % 2);
        return decimalTo2(decimal / 2, answer);
    }
    else {
        return answer;
    }
}

QString Widget::undecimalTo2(double undecimal, QString answer, int step) {
    if (step < 10) {
        ++step;
        int z = undecimal * 2;
        answer += QString::number(z);
        return undecimalTo2(undecimal * 2 - z, answer, step);
    }
    else return answer;
}

