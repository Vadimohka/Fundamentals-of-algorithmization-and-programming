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

QString Dialog::getLine()
{
    return ui->lineEdit->text();
}

void Dialog::setLabel(QString label)
{
    ui->label->setText(label);
}


