#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> tableWidget -> setColumnWidth( 0 , 120 );
    ui -> tableWidget -> setColumnWidth( 1 , 120 );
    ui -> tableWidget -> setColumnWidth( 2 , 120 );
    ui -> tableWidget -> setColumnWidth( 3 , 120 );
    ui -> tableWidget -> setColumnWidth( 4 , 120 );
    birthdayDate.setValue( 1 , 1 , 1 );

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow :: CheckIfOK( QString line )
{

    long long i = 0, newDay, newMonth, newYear;

    newDay = ( line.at( i ).unicode() - 48 ) * 10 + line.at( i + 1 ).unicode() - 48;
    newMonth = ( line.at( i + 3 ).unicode() - 48 ) * 10 + line.at( i + 4 ).unicode() - 48;
    newYear = ( ( ( line.at( i + 6 ).unicode() - 48 ) * 10 + line.at( i + 7 ).unicode() - 48 ) * 10 + line.at( i + 8 ).unicode() - 48 ) * 10 + line.at( i + 9 ).unicode() - 48;

    if( line.length() != 10 || newDay > 31 || newMonth > 12 || !( line[ 2 ] == '.' && line[ 5 ] == '.' ) || ( ( newMonth <= 7 && newMonth % 2 == 1 && newDay > 31 ) || ( newMonth > 7 && newMonth % 2 == 0 && newDay > 31 ) ) || ( ( newMonth <= 7 && newMonth % 2 == 0 && newDay > 30 ) || ( newMonth > 7 && newMonth % 2 == 1 && newDay > 30 ) ) || ( newMonth == 2 && newYear % 4 == 0 && newDay > 29 ) || ( newMonth == 2 && newDay > 28 ) )
    {
        Vsio_Huinja();
        return true;

    }


    return false;

}

void MainWindow::on_pushButtonEnterValue_clicked()
{

    //long long i = Lines;

    PathS = QFileDialog :: getOpenFileName( this , "Open file, be a Sigma" , "/home/dima-bilan-228" );

    QFile File( PathS );
    QString StringTemp;
    QString StringData = "";
    if( File.open( QIODevice :: ReadOnly ) )
    {

        QTextStream stream( &File );
        while( stream.atEnd() == false )
        {

            StringTemp = stream.readLine();

            if( CheckIfOK( StringTemp ) )
                return;

            StringData += StringTemp;
            ++ Lines;

        }

    }else{

        Nichevo nich;
        nich.setModal( true );
        nich.exec();

    }

    long long i = 0, newDay, newMonth, newYear;
    Date temDate;

    while( i < StringData.length() )
    {

        newDay = ( StringData.at( i ).unicode() - 48 ) * 10 + StringData.at( i + 1 ).unicode() - 48;
        newMonth = ( StringData.at( i + 3 ).unicode() - 48 ) * 10 + StringData.at( i + 4 ).unicode() - 48;
        newYear = ( ( ( StringData.at( i + 6 ).unicode() - 48 ) * 10 + StringData.at( i + 7 ).unicode() - 48 ) * 10 + StringData.at( i + 8 ).unicode() - 48 ) * 10 + StringData.at( i + 9 ).unicode() - 48;

        temDate.setValue( newDay , newMonth , newYear );
        Dates.push_back( temDate );

        i += 10;

    }

    PutDateToTable();

}

void MainWindow::on_pushButtonNextDay_clicked()
{

    for( long long i = 0 ; i < Lines ; ++ i )
    {

        ui -> tableWidget -> removeRow( 0 );

    }

    Date tempDate;

    ui -> tableWidget -> setRowCount( Lines );

    for( long long i = 0 ; i < Lines ; ++ i )
    {

        tempDate = Dates[ i ].getNextDate();

        QTableWidgetItem* item []= {

            new QTableWidgetItem( QString :: number( tempDate.getDateDay() ) ),
            new QTableWidgetItem( QString :: number(  tempDate.getDateMonth() ) ),
            new QTableWidgetItem( QString :: number(  tempDate.getDateYear() ) ),
            new QTableWidgetItem( QString :: number(  tempDate.getDifference( birthdayDate , true ) ) ),
            new QTableWidgetItem( tempDate.IsLeap() ),

        };

        ui -> tableWidget -> setItem( i , 0 , item[ 0 ] );
        ui -> tableWidget -> setItem( i , 1 , item[ 1 ] );
        ui -> tableWidget -> setItem( i , 2 , item[ 2 ] );
        ui -> tableWidget -> setItem( i , 3 , item[ 3 ] );
        ui -> tableWidget -> setItem( i , 4 , item[ 4 ] );

    }

}

void MainWindow::on_pushButtonPrevDay_clicked()
{

    for( long long i = 0 ; i < Lines ; ++ i )
    {

        ui -> tableWidget -> removeRow( 0 );

    }

    Date tempDate;

    ui -> tableWidget -> setRowCount( Lines );

    for( long long i = 0 ; i < Lines ; ++ i )
    {

        tempDate = Dates[ i ].getPreviusDate();

        QTableWidgetItem* item []= {

            new QTableWidgetItem( QString :: number( tempDate.getDateDay() ) ),
            new QTableWidgetItem( QString :: number(  tempDate.getDateMonth() ) ),
            new QTableWidgetItem( QString :: number(  tempDate.getDateYear() ) ),
            new QTableWidgetItem( QString :: number(  tempDate.getDifference( birthdayDate , true ) ) ),
            new QTableWidgetItem( tempDate.IsLeap() ),

        };

        ui -> tableWidget -> setItem( i , 0 , item[ 0 ] );
        ui -> tableWidget -> setItem( i , 1 , item[ 1 ] );
        ui -> tableWidget -> setItem( i , 2 , item[ 2 ] );
        ui -> tableWidget -> setItem( i , 3 , item[ 3 ] );
        ui -> tableWidget -> setItem( i , 4 , item[ 4 ] );

    }

}

void MainWindow::on_pushButtonBirth_clicked()
{

    QString tempData = ui -> textEditBirth -> toPlainText();
    if( CheckIfOK( tempData ) )
        return;

    long long newDay, newMonth, newYear;

    newDay = ( tempData.at( 0 ).unicode() - 48 ) * 10 + tempData.at( 1 ).unicode() - 48;
    newMonth = ( tempData.at( 3 ).unicode() - 48 ) * 10 + tempData.at( 4 ).unicode() - 48;
    newYear = ( ( ( tempData.at( 6 ).unicode() - 48 ) * 10 + tempData.at( 7 ).unicode() - 48 ) * 10 + tempData.at( 8 ).unicode() - 48 ) * 10 + tempData.at( 9 ).unicode() - 48;

    birthdayDate.setValue( newDay , newMonth , newYear );

    PutDateToTable();

}

void MainWindow :: Vsio_Huinja()
{

    this -> hide();
    errorMessage errorchik;
    errorchik.setModal( true );
    errorchik.exec();

}

void MainWindow :: PutDateToTable()
{

    for( long long i = 0 ; i < Dates.size() ; ++ i )
    {

        ui -> tableWidget -> removeRow( 0 );

    }

    ui -> tableWidget -> setRowCount( Lines );

    for( long long i = 0 ; i < Dates.size() ; ++ i )
    {

        QTableWidgetItem* item []= {

            new QTableWidgetItem( QString :: number(  Dates[ i ].getDateDay() ) ),
            new QTableWidgetItem( QString :: number(  Dates[ i ].getDateMonth() ) ),
            new QTableWidgetItem( QString :: number(  Dates[ i ].getDateYear() ) ),
            new QTableWidgetItem( QString :: number(  Dates[ i ].getDifference( birthdayDate , true ) ) ),
            new QTableWidgetItem( Dates[ i ].IsLeap() ),

        };

        ui -> tableWidget -> setItem( i , 0 , item[ 0 ] );
        ui -> tableWidget -> setItem( i , 1 , item[ 1 ] );
        ui -> tableWidget -> setItem( i , 2 , item[ 2 ] );
        ui -> tableWidget -> setItem( i , 3 , item[ 3 ] );
        ui -> tableWidget -> setItem( i , 4 , item[ 4 ] );


    }

}

void MainWindow::on_pushButton_clicked()
{

    QString tempData = ui -> textEdit -> toPlainText();
    if( CheckIfOK( tempData ) )
        return;

    long long newDay, newMonth, newYear;
    Date temDate;

    newDay = ( tempData.at( 0 ).unicode() - 48 ) * 10 + tempData.at( 1 ).unicode() - 48;
    newMonth = ( tempData.at( 3 ).unicode() - 48 ) * 10 + tempData.at( 4 ).unicode() - 48;
    newYear = ( ( ( tempData.at( 6 ).unicode() - 48 ) * 10 + tempData.at( 7 ).unicode() - 48 ) * 10 + tempData.at( 8 ).unicode() - 48 ) * 10 + tempData.at( 9 ).unicode() - 48;

    temDate.setValue( newDay , newMonth , newYear );
    Dates.push_back( temDate );

    ++ Lines;

    PutDateToTable();

}

void MainWindow::on_pushButtonWriteDown_clicked()
{

    QString Path = QFileDialog :: getOpenFileName( this , "Open file, be a Sigma" , "/home/dima-bilan-228" );


    QFile File( Path );
    QTextStream output( &File );

    if( File.open(QIODevice::WriteOnly | QIODevice::Text) )
    {

        for( long long i = 0 ; i < Dates.size() ; ++ i )
        {

            if( Dates[ i ].getDateDay() < 10 )
                output << "0";

            output << QString :: number( Dates[ i ].getDateDay() );

            output << "." ;

            if( Dates[ i ].getDateMonth() < 10 )
                output << "0";

            output << QString :: number( Dates[ i ].getDateMonth() );

            output << ".";
            if( Dates[ i ].getDateYear() < 10 )
            {

                output << "000" << QString :: number( Dates[ i ].getDateYear() ) << "\n";

            }else if( Dates[ i ].getDateYear() < 100 ){

                output << "00" << QString :: number( Dates[ i ].getDateYear() ) << "\n";

            }else if( Dates[ i ].getDateYear() < 1000 ){

                output << "0" << QString :: number( Dates[ i ].getDateYear() ) << "\n";

            }else{

                output << QString :: number( Dates[ i ].getDateYear() ) << "\n";

            }

        }

    }

    Ura ura;
    ura.setModal( true );
    ura.setPathLable( Path );
    ura.exec();

}

