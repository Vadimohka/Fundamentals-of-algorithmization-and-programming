#include "errormenu.h"
#include "ui_errormenu.h"

ErrorMenu::ErrorMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ErrorMenu)
{
    ui->setupUi(this);
}

ErrorMenu::~ErrorMenu()
{
    delete ui;
}
