#include "widget.h"
#include "ui_widget.h"

#include <QIntValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QIntValidator* v = new QIntValidator();
    ui->lineEdit->setValidator(v);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qint64 num = ui->lineEdit->text().toLongLong();
    QString bin = decimalToBinary(num);
    std::reverse(bin.begin(), bin.end());
    ui->label_3->setText(bin);
}

QString Widget::decimalToBinary(qint64 num) {
    if (num == 0) {
        return "";
    } else {
        qint64 remainder = num % 2;
        QString result = QString::number(remainder);
        result.append(decimalToBinary((num / 2)));
        return result;
    }
}

