#include "hanoibashni.h"
#include "ui_hanoibashni.h"

HanoiBashni::HanoiBashni(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HanoiBashni)
{
    ui->setupUi(this);

    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    scene = new QGraphicsScene( this );
    ui -> graphicsView -> setScene( scene );
    scene -> setSceneRect( -600 , -250 , 1200 , 500 );

    brush = QBrush( Qt :: SolidPattern );
    pen = QPen( Qt :: SolidPattern );

    brush.setColor( QColorConstants :: Svg :: brown );
    pen.setColor( QColorConstants :: Svg :: brown );

    item = new QGraphicsRectItem;
    item -> setBrush( brush );
    item -> setPen( pen );
    item -> setRect( -395 , 250 , 10 , -370 );
    scene -> addItem( item );

    item = new QGraphicsRectItem;
    item -> setBrush( brush );
    item -> setPen( pen );
    item -> setRect( 5 , 250 , 10 , -370 );
    scene -> addItem( item );

    item = new QGraphicsRectItem;
    item -> setBrush( brush );
    item -> setPen( pen );
    item -> setRect( 405 , 250 , 10 , -370 );
    scene -> addItem( item );


    item = new QGraphicsRectItem;
    brush.setColor( Qt :: black );
    pen.setColor( Qt :: black );
    item -> setBrush( brush );
    item -> setPen( pen );
    item -> setRect( -700 , 260 , 1400 , -10 );
    scene -> addItem( item );



}

HanoiBashni::~HanoiBashni()
{
    delete ui;
}

void HanoiBashni :: makeBashni( long long Ammount )
{
    this->Ammount = Ammount;
    whereDisk = new QChar[ Ammount ];
    whereMove = new QChar[ Ammount ];
    disks = new QGraphicsRectItem* [ Ammount ];

    for( long long i = 0 ; i < Ammount ; ++ i )
    {

        whereMove[ i ] = 'A';
        whereDisk[ i ] = 'A';
        disks[ i ] = new QGraphicsRectItem;
        disks[ i ] -> setRect( -590 + i * 10 , 250 - i * 15 , 400 - i * 10 * 2 , -15 );
        brush.setColor( QColor( QRandomGenerator :: global() -> bounded( 0 , 255 ) , QRandomGenerator :: global() -> bounded( 0 , 255 ) , QRandomGenerator :: global() -> bounded( 0 , 255 ) ) );
        pen.setColor( QColor( QRandomGenerator :: global() -> bounded( 0 , 255 ) , QRandomGenerator :: global() -> bounded( 0 , 255 ) , QRandomGenerator :: global() -> bounded( 0 , 255 ) ) );
        disks[ i ] -> setBrush( brush );
        disks[ i ] -> setPen( pen );
        scene -> addItem( disks[ i ] );
        //disks[ i ] = disk;

    }

    whereDisk[ 0 ] = 'A';
    whereMove[ 0 ] = 'C';

}

void HanoiBashni :: moveToBashni( long long pos )
{

    QChar whereMV;

    if( pos == Ammount - 1 )
    {

        moveFunct( pos );

    }
    else if( whereDisk[ pos + 1 ] != whereDisk[ pos ] )
    {

        if( whereMove[ pos ] == whereDisk[ pos ] )
        {

            whereMove[ pos + 1 ] = whereMove[ pos ];
            moveToBashni( pos + 1 );

        }
        else
        {

            moveFunct( pos );

        }

    }
    else
    {

        if( whereDisk[ pos + 1 ] == 'A' )
        {

            if( whereMove[ pos ] == 'B' )
            {

                whereMV = 'C';

            }
            else
            {

                whereMV = 'B';

            }

        }
        else if( whereDisk[ pos + 1 ] == 'B' )
        {

            if( whereMove[ pos ] == 'A' )
            {

                whereMV = 'C';

            }
            else
            {

                whereMV = 'A';

            }

        }
        else
        {

            if( whereMove[ pos ] == 'A' )
            {

                whereMV = 'B';

            }
            else
            {

                whereMV = 'A';

            }

        }

        whereMove[ pos + 1 ] = whereMV;
        moveToBashni( pos + 1 );
        moveFunct( pos );
        whereMove[ pos + 1 ] = whereDisk[ pos ];
        moveToBashni( pos + 1 );

    }



}

void HanoiBashni :: moveFunct( long long pos )
{

    long long movement = whereMove[ pos ].unicode() - whereDisk[ pos ].unicode();

    ui->graphicsView->viewport()->update();

    while( disks[ pos ] -> y() - ( ( long long )( moveSpeed / 100 ) ) >= -390 + pos * 15 ){
        disks[ pos ]->setY( disks[ pos ] -> y() - ( ( long long )( moveSpeed / 100 ) ) );
        QCoreApplication::processEvents();
        scene -> update();
    }

    disks[ pos ]->setY( -390 + pos * 15 );
    QCoreApplication::processEvents();

    long long posX = disks[ pos ]->x() + movement * 400;

    movement = ( movement == -2 || movement == 2 ) ? movement / 2 : movement;

    if( movement < 0 )
        while( disks[ pos ] -> x() + movement * ( ( long long )( moveSpeed / 100 ) ) >= posX )
        {

            disks[ pos ]->setX( disks[ pos ] -> x() + movement * ( ( long long )( moveSpeed / 100 ) ) );
            QCoreApplication::processEvents();
            scene -> update();

        }
    else
        while( disks[ pos ] -> x() <= posX )
        {

            disks[ pos ]->setX( disks[ pos ] -> x() + movement * ( ( long long )( moveSpeed / 100 ) ) );
            QCoreApplication::processEvents();
            scene -> update();

        }

    disks[ pos ]->setX( posX );
    QCoreApplication::processEvents();

    long long count = 0;

    for( long long i = pos - 1 ; i >= 0 ; -- i )
    {

        if( whereMove[ pos ] == whereDisk[ i ] )
            ++ count;

    }

    long long posY = disks[ pos ]->y();

    for( long long i = disks[ pos ]->y() ; i + ( ( long long )( moveSpeed / 100 ) ) <= 0 + ( pos - count ) * 15; i += ( ( long long )( moveSpeed / 100 ) ) ){
        disks[ pos ] -> setY( i );
        QCoreApplication::processEvents();
        scene -> update();
    }

    disks[ pos ] -> setY( 0 + ( pos - count ) * 15 );
    QCoreApplication::processEvents();

    whereDisk[ pos ] = whereMove[ pos ];

    scene -> update();


}

void HanoiBashni::on_pushButtonStart_clicked()
{

    moveToBashni( 0 );
    TryAgain tryAgain;
    tryAgain.setModal( true );
    tryAgain.ChangeMem( Ammount );
    this -> close();
    tryAgain.exec();

}



void HanoiBashni::on_horizontalSlider_valueChanged(int value)
{

    moveSpeed = value;

}

