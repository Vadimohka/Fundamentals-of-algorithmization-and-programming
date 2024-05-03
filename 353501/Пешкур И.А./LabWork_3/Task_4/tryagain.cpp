#include "tryagain.h"
#include "ui_tryagain.h"

TryAgain::TryAgain(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TryAgain)
{
    ui->setupUi(this);

    ui -> pushButtonAgain -> setStyleSheet( "background-color: blue" );
    ui -> pushButtonStop -> setStyleSheet( "background-color: red" );

}

TryAgain::~TryAgain()
{
    delete ui;
}

void TryAgain::on_pushButtonAgain_clicked()
{

    this -> close();
    HanoiBashni hanoiBashni;
    hanoiBashni.setModal( true );
    hanoiBashni.makeBashni( mem );
    hanoiBashni.exec();

}


void TryAgain::on_pushButtonStop_clicked()
{

    this -> close();

}

void TryAgain :: ChangeMem( long long a )
{

    mem = a;

}

