#include "menu.h"

#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QWidget(parent, Qt::FramelessWindowHint)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->background->setPixmap(QPixmap("../Sources/Dragon.png"));
    ui->background->setScaledContents(true);
    ui->background->resize(size());
    ui->background->lower();
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_close_clicked()
{
    emit Close();
}

void Menu::on_pushButton_continue_clicked()
{
    emit Continue();
}

void Menu::on_pushButton_3_clicked()
{
    emit NewGame();
}
