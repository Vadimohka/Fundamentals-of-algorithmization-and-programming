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

QStringList Widget::hanoi(int n, char from, char to, char spare)
{
    QStringList stringList;
    if (n > 0) {
        stringList.append(hanoi(n - 1, from, spare, to));
        QString result;
        result.append("Ring number ").append(QString::number(n)).append(": ").append(from).append(" -> ").append(to);
        stringList.append(result);
        stringList.append(hanoi(n - 1, spare, to, from));
    }
    return stringList;
}

void Widget::on_pushButton_clicked()
{
    QStringList stringList = hanoi(ui->lineEdit->text().toLongLong(), 'A', 'C', 'B');
    ui->listWidget->clear();
    ui->listWidget->addItems(stringList);
}

