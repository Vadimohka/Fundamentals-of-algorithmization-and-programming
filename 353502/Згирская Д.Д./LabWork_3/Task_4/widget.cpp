#include <iostream>
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

void Widget::hanoi(int n, QString start, QString temp, QString end) {
    if (n == 0) return;
    hanoi(n - 1, start, end, temp);
    qDebug() << n << ":" << start << "->" << end;
    hanoi(n - 1, temp, start, end);
    return;
}
void Widget::on_getSteps_clicked() {
    QString line = ui->writeNumber_lineEdit->text();
    if (setNumber(line)) {
        hanoi(_number, "A", "B", "C");
    }
    else {
        ui->writeNumber_lineEdit->setText("Wrong input!");
    }

}

bool Widget::setNumber(QString line) {
    _number = line.toULongLong();
    if (_number == 0 && line[0] == "-" || _number == 0 && line[0] != "0") {
        return false;
    }
    else return true;
}

