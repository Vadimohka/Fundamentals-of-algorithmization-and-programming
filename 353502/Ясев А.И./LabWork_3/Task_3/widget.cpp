#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QIntValidator>
#include <QtMath>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QIntValidator *v = new QIntValidator();
    ui->lineEdit->setValidator(v);
}

Widget::~Widget()
{
    delete ui;
}

qint64 Widget::reverse(qint64 n)
{
    if (n < 10) {
        return n;
    } else {
        int lastDigit = n % 10;
        n /= 10;
        return lastDigit * pow(10, floor(log10(n)) + 1) + reverse(n);
    }
}
void Widget::on_pushButton_clicked()
{
    qint64 num = ui->lineEdit->text().toLongLong();
    ui->lineEdit->setText(QString::number(reverse(num)));
}

