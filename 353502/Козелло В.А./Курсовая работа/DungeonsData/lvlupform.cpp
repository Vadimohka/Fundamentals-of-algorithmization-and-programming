#include "lvlupform.h"
#include "ui_lvlupform.h"

LvlUpForm::LvlUpForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LvlUpForm)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowStaysOnTopHint);
}

LvlUpForm::~LvlUpForm()
{
    delete ui;
}

void LvlUpForm::on_selectButton_clicked()
{
    emit Choose(ui->chooseBox->currentIndex());
    this->close();
}
