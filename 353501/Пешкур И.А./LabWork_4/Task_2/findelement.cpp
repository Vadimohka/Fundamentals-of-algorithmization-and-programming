#include "findelement.h"
#include "ui_findelement.h"

FIndElement::FIndElement(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FIndElement)
{
    ui->setupUi(this);
}

FIndElement::~FIndElement()
{
    delete ui;
}

void FIndElement::on_pushButtonEnter_clicked()
{

    long long Number = QStrToLong( ui -> lineEdit -> text() );

    long long index = MainWindow :: BinSearch( Number , 0 , 125 , 249 );

    MainWindow :: findedElement( index , Number );

}

long long FIndElement :: QStrToLong( QString s )
{

    long long Number = 0;
    for( long long i = s.length() - 1 ; i >= 0 ; -- i )
    {

        Number = Number * 10 + s.at( i ).unicode() - 48;

    }

    return Number;

}
