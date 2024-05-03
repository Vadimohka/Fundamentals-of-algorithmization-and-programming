#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinBox->setRange(0, 4);
    ui->spinBox_2->setRange(0, 9999);

    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        if((ui->spinBox->value()==3&&ui->spinBox_2->value()>12)||(ui->spinBox->value()==4&&ui->spinBox_2->value()>0)){
            ui->label_3->setText("Я запрещаю вам ломать мой компьютер");
            return;
        }
        ui->pushButton->setDisabled(1);
        ui->label_3->setText(QString::number(calculate(ui->spinBox->value(), ui->spinBox_2->value())));
        ui->pushButton->setEnabled(1);
    });
}

Widget::~Widget()
{
    delete ui;
}

uint16_t Widget::calculate(uint16_t m, uint16_t n){
    if(m>0 && n>0) return calculate(m-1, calculate(m, n-1));
    if(m>0 && n==0) return calculate(m-1, 1);
    else return n+1;
}
