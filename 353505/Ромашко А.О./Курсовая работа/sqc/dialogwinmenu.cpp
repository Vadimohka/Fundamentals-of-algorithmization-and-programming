#include "dialogwinmenu.h"
#include "ui_dialogwinmenu.h"

DialogWinMenu::DialogWinMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogWinMenu)
{
    ui->setupUi(this);
}

DialogWinMenu::~DialogWinMenu()
{
    delete ui;
}

void DialogWinMenu::takeInfoMONEYCARDHP(int m, Card *c, int h){this->money=m;this->card=c;this->hp=h;}

void DialogWinMenu::open()
{
    ui->label_Card->setText("Найдена новая карта");
    ui->label_UpHP->setText("Здоровьe +"+QString::number(hp));
    ui->label_UpMoney->setText("Монеты +"+QString::number(money));
    this->setFocus();
    setWindowTitle("You winner!!!");
    this->showNormal();
}
