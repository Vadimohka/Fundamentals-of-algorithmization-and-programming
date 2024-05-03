#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui -> tableWidget -> setColumnWidth( 0 , 100 );
    ui -> tableWidget -> setColumnWidth( 1 , 300 );
    ui -> tableWidget -> setColumnWidth( 2 , 200 );

    setDishes();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: setDishes()
{

    dishesName.push_back( "Water" );
    dishesName.push_back( "Shashlik" );
    dishesName.push_back( "Paket" );
    dishesName.push_back( "Pivo" );
    dishesName.push_back( "Bulik" );
    dishesName.push_back( "Kalian" );
    dishesName.push_back( "Grecha" );
    dishesName.push_back( "Ris" );

    for( long long i = 0 ; i < dishesName.size() ; ++ i )
    {

        ui -> comboBoxFood1 -> addItem( dishesName[ i ] );
        ui -> comboBoxFood2 -> addItem( dishesName[ i ] );
        dishesPrice[ dishesName[ i ] ] = i * 10 + i * 3 + 12;

    }

}

void MainWindow::on_pushButton_4_clicked()
{

    RestarauntMenu restmen;
    restmen.setModal( true );
    restmen.exec();

}

void MainWindow :: setTable()
{

    for( long long i = 0 ; i < Lines ; ++ i )
    {

        ui -> tableWidget -> removeRow( 0 );

    }

    ui -> tableWidget -> setRowCount( Lines );

    for( long long i = 0 ; i < Lines ; ++ i )
    {

        QTableWidgetItem* item []= {

            new QTableWidgetItem( QString :: number( Orders[ i ].getTable() ) ),
            new QTableWidgetItem( Orders[ i ].getDishes() ),
            new QTableWidgetItem( QString :: number( Orders[ i ].getTotalPrice() ) )

        };

        ui -> tableWidget -> setItem( i , 0 , item[ 0 ] );
        ui -> tableWidget -> setItem( i , 1 , item[ 1 ] );
        ui -> tableWidget -> setItem( i , 2 , item[ 2 ] );


    }

    QString biggestAmount;
    long long MaxAmmount = 0;

    for( long long i = 0 ; i < dishesName.size() ; ++ i )
    {

        if( MaxAmmount < dishesAmmount[ dishesName[ i ] ] )
        {

            MaxAmmount = dishesAmmount[ dishesName[ i ] ];
            biggestAmount = dishesName[ i ];

        }

    }

    ui -> labelMostPopularDish -> setText( biggestAmount );

}

void MainWindow::on_pushButton_clicked()
{

    Order tempOrder;

    tempOrder.setValue( ui -> spinBoxTable -> value() , ui -> comboBoxFood1 -> currentText() , ui -> spinBoxAmmount1 -> value() , dishesPrice[ ui -> comboBoxFood1 -> currentText() ] );

    Orders.push_back( tempOrder );

    ++ dishesAmmount[ ui -> comboBoxFood1 -> currentText() ];

    ++ Lines;

    ui -> comboBoxOrder -> addItem( QString :: number( Lines ) );
    ui -> comboBoxOrder2 -> addItem( QString :: number( Lines ) );

    setTable();

}

void MainWindow::on_pushButton_2_clicked()
{

    long long OrderNumber = QSToLong( ui -> comboBoxOrder -> currentText() ) - 1;

    Orders[ OrderNumber ].setValue( Orders[ OrderNumber ].getTable() , ui -> comboBoxFood2 -> currentText() , ui -> spinBoxAmmount2 -> value() , dishesPrice[ ui -> comboBoxFood2 -> currentText() ] );

    ++ dishesAmmount[ ui -> comboBoxFood2 -> currentText() ];

    setTable();

}

long long MainWindow :: QSToLong( QString number )
{

    long long Res = 0, i = 0;
    while( i < number.length() )
    {

        Res = Res * 10 + number.at( i ).unicode() - 48;
        ++ i;

    }

    return Res;

}

void MainWindow :: sortByPrice()
{

    for( long long i = 0 ; i < Orders.size() ; ++ i )
    {

        for( long long j = i + 1 ; j < Orders.size() ; ++ j )
        {

            if( Orders[ i ].getTotalPrice() > Orders[ j ].getTotalPrice() )
            {

                std :: swap( Orders[ i ] , Orders[ j ] );

            }

        }

    }

}

void MainWindow::on_pushButtonSortByPriceUp_clicked()
{

    sortByPrice();

    setTable();

}

void MainWindow::on_pushButtonSortByPriceDown_clicked()
{

    sortByPrice();

    reversOrders();

    setTable();

}

void MainWindow :: reversOrders()
{

    for( long long i = 0 ; i < Orders.size() / 2 ; ++ i )
    {

        std :: swap( Orders[ i ] , Orders[ Orders.size() - i - 1 ] );

    }

}

void MainWindow::on_pushButtonDeleteOrder_clicked()
{

    long long orderNumber = QSToLong( ui -> comboBoxOrder2 -> currentText() );

    for( long long i = 0 ; i < Orders[ orderNumber - 1 ].Dishes.size() ; ++ i )
    {

        -- dishesAmmount[ Orders[ orderNumber - 1 ].Dishes[ i ] ];

    }

    Orders.remove( orderNumber - 1 );
    ui -> comboBoxOrder -> clear();
    ui -> comboBoxOrder2 -> clear();

    for( long long i = 0 ; i < Lines - 1 ; ++ i )
    {

        ui -> comboBoxOrder -> addItem( QString :: number( i + 1 ) );
        ui -> comboBoxOrder2 -> addItem( QString :: number( i + 1 ) );

    }

    -- Lines;

    setTable();

}

void MainWindow::on_pushButtonRead_clicked()
{

    QString Path = QFileDialog :: getOpenFileName( nullptr , "Sigma heronwater" , "/home/dima-bilan-228" );
    QFile File( Path );

    if( File.open( QIODevice :: ReadOnly | QIODevice :: Text ) )
    {

        QTextStream input( &File );
        QString firstLine;

        long long TableNumber;
        QString tempDish;
        long long tempAmmount;

        long long i = 0;

        while( !input.atEnd() )
        {

            firstLine += input.readLine() + " ";
            ++ Lines;
            ui -> comboBoxOrder -> addItem( QString :: number( Lines ) );
            ui -> comboBoxOrder2 -> addItem( QString :: number( Lines ) );

        }


        while( i < firstLine.length() )
        {

            TableNumber = 0;

            while( firstLine.at( i ).unicode() - 48 < 10 && firstLine.at( i ).unicode() - 48 >= 0 && i < firstLine.length() )
            {

                TableNumber = TableNumber * 10 + firstLine.at( i ).unicode() - 48;
                ++ i;

            }

            Order tempOrder;

            while( i < firstLine.length() && firstLine.at( i ) != ' ' )
            {

                tempDish = "";
                tempAmmount = 0;

                while( ( firstLine.at( i ).unicode() - 48 > 9 || firstLine.at( i ).unicode() - 48 < 0 ) && i < firstLine.length() )
                {

                    tempDish += firstLine.at( i );
                    ++ i;

                }

                while( firstLine.at( i ).unicode() - 48 < 10 && i < firstLine.length() && firstLine.at( i ).unicode() - 48 >= 0 && firstLine.at( i ) != ' ' )
                {

                    tempAmmount = tempAmmount * 10 + firstLine.at( i ).unicode() - 48;
                    ++ i;

                }

                if( TableNumber == 0 || tempAmmount == 0 || dishesPrice[ tempDish ] == 0 )
                {

                    ErrorMessage();
                    return;

                }

                tempOrder.setValue( TableNumber , tempDish , tempAmmount , dishesPrice[ tempDish ] );
                if( dishesPrice[ tempDish ] == 0 )
                {

                    ErrorMessage();
                    return;

                }
                ++ dishesAmmount[ tempDish ];

            }

            ++ i;

            Orders.push_back( tempOrder );

        }

    }else{

        Nichevo nich;
        nich.setModal( true );
        nich.exec();

    }

    setTable();

}

void MainWindow :: ErrorMessage()
{

    this -> hide();
    ErrorMenu ermenu;
    ermenu.setModal( true );
    ermenu.exec();

}

void MainWindow::on_pushButtonWrite_clicked()
{

    QString Path = "Orders";

    QFile File( Path );
    if( File.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {

        QTextStream output( &File );

        for( long long i = 0 ; i < Orders.size() ; ++ i )
        {

            output << QString :: number( Orders[ i ].getTable() );

            for( long long j = 0 ; j < Orders[ i ].Dishes.size() - 1 ; ++ j )
            {

                output << Orders[ i ].Dishes[ j ] << QString :: number( Orders[ i ].Ammount[ j ] ) << " ";

            }

            output << Orders[ i ].Dishes[ Orders[ i ].Dishes.size() - 1 ] << QString :: number( Orders[ i ].Ammount[ Orders[ i ].Dishes.size() - 1 ] ) << "\n";

        }

    }

    Ura ura;
    ura.setModal( true );
    ura.setPathLable( Path );
    ura.exec();

}

