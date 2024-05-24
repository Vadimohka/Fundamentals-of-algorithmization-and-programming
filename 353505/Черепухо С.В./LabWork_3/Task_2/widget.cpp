#include "widget.h"
#include "ui_widget.h"

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

unsigned long long Widget::acc(unsigned long long m, unsigned long long n)
{
    if(n > 5)
    {
        if(m == 0)
            return n + 1;
        if(m == 1)
            return n + 2;
        if(m == 2)
            return 2*n + 3;
    }

    if (m == 0)
        return n + 1;
    else if(m > 0 && n == 0)
        return acc(m - 1, 1);
    else
        return acc(m - 1, acc(m, n - 1));
}

void Widget::on_pushButton_clicked()
{
    unsigned long long n = ui->spinBox_2->value();

    if(n > 5)
        ui->spinBox->setMaximum(2);
    else if(n > 1 && n < 6)
        ui->spinBox->setMaximum(3);
    else if(n == 1)
        ui->spinBox->setMaximum(4);
    else if(n == 0)
        ui->spinBox->setMaximum(4);

    ui->label_4->setText(QString::number(acc(ui->spinBox->value(), ui->spinBox_2->value())));
}

