#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinBox->setRange(1, 999999999);

    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        ui->answerLavel->setText(QString::number(reverseNumber(ui->spinBox->value())));
    });
}

Widget::~Widget()
{
    delete ui;
}

uint8_t Widget::rankOfNumber(int64_t number, uint8_t rank = 0)
{
    return number==0 ? rank : rankOfNumber(number/10, rank + 1);
}

uint64_t Widget::reverseNumber(int64_t number)
{
    return number<10 ? number : (number % 10) * pow(10, rankOfNumber(number)-1) + reverseNumber(number / 10);
}
