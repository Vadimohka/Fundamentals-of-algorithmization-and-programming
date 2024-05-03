#include "dialoginputpushback.h"
#include "ui_dialoginputpushback.h"

DialogInputPushBack::DialogInputPushBack(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogInputPushBack)
{
    ui->setupUi(this);
}

DialogInputPushBack::~DialogInputPushBack()
{
    delete ui;
}

int DialogInputPushBack::getValue()
{
    return ui->spinBox->value();
}

void DialogInputPushBack::setRange(int min, int max)
{
    ui->spinBox->setRange(min, max);
}

void DialogInputPushBack::setValue(int value)
{
    ui->spinBox->setValue(value);
}
