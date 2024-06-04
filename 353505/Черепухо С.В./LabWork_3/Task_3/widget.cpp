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

long long Widget::revers(long long ch)
{
    if (ch == 0)
        return 0;

    long long des = 1, temp_ch = ch;

    while (temp_ch != 0)
    {
        temp_ch /= 10;
        des *= 10;
    }

    des /= 10;

    return des * (ch % 10) + revers(ch / 10);
}

void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    QString bet = arg1;
    bet.removeLast();

    for(int i = 0; i < arg1.size(); i++)
    {
        if(arg1[i] < '1' || arg1[i] > '9')
            ui->lineEdit->setText("");
    }

    if(arg1.size() > 18)
    {
        ui->lineEdit->setText(bet);
        return;
    }
}


void Widget::on_pushButton_clicked()
{
    ui->label_3->setText(QString::number(revers(ui->lineEdit->text().toLongLong())));
}

