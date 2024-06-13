#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QIntValidator *v = new QIntValidator;
    ui->lineEdit->setValidator(v);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::getInt()
{
    return ui->lineEdit->text().toInt();
}
