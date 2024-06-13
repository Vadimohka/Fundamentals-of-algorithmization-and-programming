#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    connect(ui->continue_button, &QPushButton::clicked, this, &Menu::continuePlay);
    ///connect(ui->main_menu_button, &QPushButton::clicked, this, &Menu::backToMainMenu);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::continuePlay()
{
    this->close();
}

void Menu::backToMainMenu() {

}
