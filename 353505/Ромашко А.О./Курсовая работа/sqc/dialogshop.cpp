#include "dialogshop.h"
#include "ui_dialogshop.h"

DialogShop::DialogShop(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogShop)
{
    ui->setupUi(this);
}

DialogShop::~DialogShop()
{
    delete ui;
}

void DialogShop::openSlot()
{
    ui->label_money->setText(QString::number(player->money));
    if(player->money<500&&epath==0)
        ui->pushButton_EasyP->setEnabled(0);
    else
        ui->pushButton_EasyP->setEnabled(1);
    if(player->money<200)
        ui->pushButton_add50hp->setEnabled(0);
    else
        ui->pushButton_add50hp->setEnabled(1);
    setWindowTitle("Магазин");
    this->setFocus();
    this->show();
}

void DialogShop::on_pushButton_EasyP_clicked()
{
    if(player->money>=500){
        ui->pushButton_EasyP->setEnabled(0);
        player->money -=500;
        epath=0;
        ui->label_money->setText(QString::number(player->money));
        emit showLines();
    }
    this->update();
}


void DialogShop::on_buttonBox_accepted()
{
    this->setFocus();
}

void DialogShop::on_pushButton_add50hp_clicked()
{
    if(player->money>=200){
        ui->pushButton_add50hp->setEnabled(0);
        player->money-=200;
        ui->label_money->setText(QString::number(player->money));
        player->upHp(50);
    }
    this->update();
}

