#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> comboBox -> addItem( "+" );
    ui -> comboBox -> addItem( "-" );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAnswer_clicked()
{

    Answer ans;
    ans.setModal( true );
    ans.getAns( LDoubleToBin( ui -> spinBoxCel -> value() , ui -> spinBoxDrob -> value() ) );
    ans.exec();

}

QString MainWindow :: LDoubleToBin( long long cel , long long mant )
{

    return QString :: number( ui -> comboBox -> currentIndex() ) + " " + LongToBin( cel ) + DoubleToBin( DROB( ( long double )mant ) );

}

long double MainWindow :: DROB( long double mant )
{

    if( mant < 1 )
        return mant;

    return DROB( mant / 10.0 );

}

QString MainWindow :: LongToBin( long long cel )
{

    if( cel == 0 )
        return "";

    return LongToBin( cel / 2 ) + QString :: number( cel % 2 );

}

QString MainWindow :: DoubleToBin( long double mant )
{

    mant *= 2.0;

    if( mant >= 1.0 )
        return "1" + DoubleToBin( mant - 1.0 );
    if( mant != 0 )
        return "0" + DoubleToBin( mant );

    return "";

}

