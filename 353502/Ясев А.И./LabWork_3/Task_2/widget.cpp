#include "widget.h"
#include "ui_widget.h"

#include <QIntValidator>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QIntValidator *v = new QIntValidator();
    ui->mEdit->setValidator(v);
    ui->nEdit->setValidator(v);
}

Widget::~Widget()
{
    delete ui;
}

qint64 Widget::ackermann(qint64 m, qint64 n)
{
    if (m == 0) {
        return n+1;
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}


void Widget::on_pushButton_clicked()
{
    qint64 m = ui->mEdit->text().toLongLong(), n = ui->nEdit->text().toLongLong();
    ui->answer->setText(QString::number(ackermann(m,n)));
}

