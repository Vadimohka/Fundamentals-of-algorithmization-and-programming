#include "answer.h"
#include "ui_answer.h"

Answer::Answer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Answer)
{
    ui->setupUi(this);
}

Answer::~Answer()
{
    delete ui;
}

void Answer :: setAnswer( long long Ans )
{

    ui -> labelAnswer -> setText( QString :: number( Ans ) );

}
