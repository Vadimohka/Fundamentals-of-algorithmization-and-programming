#include "dialoglose.h"
#include "ui_dialoglose.h"

DialogLOSE::DialogLOSE(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogLOSE)
{


    ui->setupUi(this);
}

DialogLOSE::~DialogLOSE()
{
    delete ui;
}

void DialogLOSE::open()
{
    setWindowTitle("You lose, AHAHAHAHAHHAHA");
    this->showNormal();
}

void DialogLOSE::on_buttonBox_accepted()
{
    emit openMainMenu();
}

