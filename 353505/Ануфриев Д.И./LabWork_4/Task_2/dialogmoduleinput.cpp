#include "dialogmoduleinput.h"
#include "ui_dialogmoduleinput.h"

DialogModuleInput::DialogModuleInput(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogModuleInput)
{
    ui->setupUi(this);
}

DialogModuleInput::~DialogModuleInput()
{
    delete ui;
}

long long DialogModuleInput::getValue()
{
    return ui->spinBox->value();
}
