#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_comboBox_2_activated(int index)
{
    indLang = index;
}

void Dialog::on_pushButton_clicked()
{
    emit signalStart(indLang);
}

