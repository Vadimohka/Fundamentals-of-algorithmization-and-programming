#include "savemenu.h"
#include "ui_savemenu.h"

SaveMenu::SaveMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SaveMenu)
{
    ui->setupUi(this);
}

SaveMenu::~SaveMenu()
{
    delete ui;
}

void SaveMenu::openSlot()
{
    SaveMenu::on_pushButton_NewGame_clicked();

    //this->showFullScreen();
    this->close();
}

void SaveMenu::on_pushButton_Back_clicked()
{
    emit SaveMenuExitSignal();
    this->close();
}

void SaveMenu::on_pushButton_NewGame_clicked()
{
    emit SaveMenuExitTGLSoSignal();
    this->close();
}


void SaveMenu::on_pushButton_OpenGame_clicked()
{
    emit SaveMenuExitTGLSoSignal();
    this->close();
}

