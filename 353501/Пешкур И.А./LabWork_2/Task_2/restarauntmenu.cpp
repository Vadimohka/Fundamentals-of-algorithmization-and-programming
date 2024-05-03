#include "restarauntmenu.h"
#include "ui_restarauntmenu.h"

RestarauntMenu::RestarauntMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RestarauntMenu)
{
    ui->setupUi(this);

    ui -> tableWidget -> setColumnWidth( 0 , 250 );
    ui -> tableWidget -> setColumnWidth( 1 , 250 );

    putToTable();

}

RestarauntMenu::~RestarauntMenu()
{
    delete ui;
}

void RestarauntMenu :: putToTable()
{

    dishesName.push_back( "Water" );
    dishesName.push_back( "Shashlik" );
    dishesName.push_back( "Paket" );
    dishesName.push_back( "Pivo" );
    dishesName.push_back( "Bulik" );
    dishesName.push_back( "Kalian" );
    dishesName.push_back( "Grecha" );
    dishesName.push_back( "Ris" );

    ui ->tableWidget -> setRowCount( dishesName.size() );

    for( long long i = 0 ; i < dishesName.size() ; ++ i )
    {
        QTableWidgetItem* item []= {

            new QTableWidgetItem( dishesName[ i ] ),
            new QTableWidgetItem( QString :: number( i * 13 + 12 ) ),

        };

        ui -> tableWidget -> setItem( i , 0 , item[ 0 ] );
        ui -> tableWidget -> setItem( i , 1 , item[ 1 ] );

    }

}
