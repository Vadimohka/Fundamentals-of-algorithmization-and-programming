#include "nichevo.h"
#include "ui_nichevo.h"

Nichevo::Nichevo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Nichevo)
{
    ui->setupUi(this);
}

Nichevo::~Nichevo()
{
    delete ui;
}
