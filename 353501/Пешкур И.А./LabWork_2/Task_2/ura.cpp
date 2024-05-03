#include "ura.h"
#include "ui_ura.h"

Ura::Ura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Ura)
{
    ui->setupUi(this);
}

Ura::~Ura()
{
    delete ui;
}

void Ura :: setPathLable( QString Path )
{

    ui -> label -> setText( Path );

}
