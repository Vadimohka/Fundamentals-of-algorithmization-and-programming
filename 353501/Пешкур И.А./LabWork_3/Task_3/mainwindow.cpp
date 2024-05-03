#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    long long Number = ui -> spinBox -> value();

    Number = reversNumber( Number );

    ui -> labelReversedNumber -> setText( QString :: number( Number ) );

}

long long MainWindow :: reversNumber( long long Number )
{

    if( Number < 10 )
        return Number;

    return ( Number % 10 ) * binPow( 10 , numberLength( Number ) - 1 ) + reversNumber( Number / 10 );

}

long long MainWindow :: binPow( long long x , long long step )
{

    if( step == 0 )
        return 1;
    if( step == 1 )
        return x;
    if( step % 2 == 0 )
        return binPow( x , step / 2 ) * binPow( x , step / 2 );

    return binPow( x , ( step - 1 ) / 2 ) * binPow( x , ( step - 1 ) / 2 ) * x;

}

long long MainWindow :: numberLength( long long Number )
{

    if( Number < 10 )
        return 1;

    return 1 + numberLength( Number / 10 );

}

