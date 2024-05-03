#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    {

        ui -> comboBox -> addItem( "Circle" );
        ui -> comboBox -> addItem( "Triangle" );
        ui -> comboBox -> addItem( "Rectangle" );
        ui -> comboBox -> addItem( "Hexagon" );
        ui -> comboBox -> addItem( "Square" );
        ui -> comboBox -> addItem( "Ellipse" );
        ui -> comboBox -> addItem( "5-pointed star");
        ui -> comboBox -> addItem( "6-pointed star");
        ui -> comboBox -> addItem( "8-pointed star");
        ui -> comboBox -> addItem( "Custom");

    }

    scene = new CustomScene( this );
    ui -> graphicsView -> setScene( scene );
    ui -> comboBox -> setCurrentIndex( 0 );

    figure = new Circle;
    scene -> addItem( figure );
    setValue();

    {

        connect( ui -> comboBox , SIGNAL( currentIndexChanged(int) ) , this , SLOT( change_figure(int) ) );
        connect( ui -> horizontalSliderMoveX , SIGNAL( valueChanged(int) ) , this , SLOT( move_figure_x(int) ) );
        connect( ui -> horizontalSliderMoveY , SIGNAL( valueChanged(int) ) , this , SLOT( move_figure_y(int) ) );
        connect( ui -> horizontalSliderRotate , SIGNAL( valueChanged(int) ) , this , SLOT( rotate_figure(int) ) );
        connect( ui -> horizontalSliderHexagonRadius , SIGNAL( valueChanged(int)) , this , SLOT( makeRadius(int) ) );
        connect( ui -> horizontalSliderEllipseRadius , SIGNAL( valueChanged(int)) , this , SLOT( makeRadius(int) ) );
        connect( ui -> horizontalSliderCircleRadius , SIGNAL( valueChanged(int)) , this , SLOT( makeRadius(int) ) );
        connect( ui -> horizontalSliderRectangleA , SIGNAL( valueChanged(int)) , this , SLOT( makeLength(int) ) );
        connect( ui -> horizontalSliderRectangleB , SIGNAL( valueChanged(int)) , this , SLOT( makeWidth(int) ) );
        connect( ui -> horizontalSliderSquareA , SIGNAL( valueChanged(int)) , this , SLOT( makeSize(int) ) );
        connect( ui -> horizontalSliderTriangleA , SIGNAL( valueChanged(int)) , this , SLOT( makeSize(int) ) );
        connect( ui -> horizontalSliderStar5Radius1 , SIGNAL( valueChanged(int)) , this , SLOT( makeRadius1(int) ) );
        connect( ui -> horizontalSliderStar5Radius2 , SIGNAL( valueChanged(int)) , this , SLOT( makeRadius2(int) ) );
        connect( ui -> horizontalSliderStar6Radius1 , SIGNAL( valueChanged(int)) , this , SLOT( makeRadius1(int) ) );
        connect( ui -> horizontalSliderStar6Radius2 , SIGNAL( valueChanged(int)) , this , SLOT( makeRadius2(int) ) );
        connect( ui -> horizontalSliderStar8Radius1 , SIGNAL( valueChanged(int)) , this , SLOT( makeRadius1(int) ) );
        connect( ui -> horizontalSliderStar8Radius2 , SIGNAL( valueChanged(int)) , this , SLOT( makeRadius2(int) ) );
        connect( ui -> horizontalSliderCenterX , SIGNAL( valueChanged(int) ) , this , SLOT( makeCenterX(int) ) );
        connect( ui -> horizontalSliderCenterY , SIGNAL( valueChanged(int) ) , this , SLOT( makeCenterY(int) ) );
        connect( scene , &CustomScene::mousePressed , this ,  &MainWindow::onMousePressed );
        connect( ui -> horizontalSliderCustomSize , SIGNAL( valueChanged(int) ) , this , SLOT( makeScale(int) ) );


    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: change_figure( int currentIndex ){

    this -> ui -> stackedWidget_2 -> setCurrentIndex( 0 );
    this -> ui -> stackedWidget -> setCurrentIndex( currentIndex );
    scene -> clear();
    wasChangingUsed = false;

    switch( currentIndex )
    {

    case 0:
        putCircle();
        break;
    case 1:
        putTriangle();
        break;
    case 2:
        putRectangle();
        break;
    case 3:
        putHexagon();
        break;
    case 4:
        putSquare();
        break;
    case 5:
        putEllipse();
        break;
    case 6:
        putStar5();
        break;
    case 7:
        putStar6();
        break;
    case 8:
        putStar8();
        break;
    case 9:
        wasChangingUsed = true;
        putKaLL();
        break;


    }

    if( wasChangingUsed )
    {

        this -> ui -> stackedWidget_2 -> setCurrentIndex( 1 );

    }else
    {

        makeCenterX( 0 );
        makeCenterY( 0 );
        setValue();

    }

    setSliderValue();

}

void MainWindow :: putHexagon()
{

    figure = new Hexagon();
    scene -> addItem( figure );

}

void MainWindow :: putCircle()
{

    figure = new Circle();
    scene -> addItem( figure );

}

void MainWindow :: putRectangle()
{

    figure = new Rectangle();
    scene -> addItem( figure );

}

void MainWindow :: putSquare()
{

    figure = new Square();
    scene -> addItem( figure );

}

void MainWindow :: putTriangle()
{

    figure = new Triangle();
    scene -> addItem( figure );

}

void MainWindow :: putEllipse()
{

    figure = new Ellipse();
    scene -> addItem( figure );

}

void MainWindow :: putStar5()
{

    figure = new Star5();
    scene -> addItem( figure );

}

void MainWindow :: putStar6()
{

    figure = new Star6();
    scene -> addItem( figure );

}

void MainWindow :: putStar8()
{

    figure = new Star8();
    scene -> addItem( figure );

}

void MainWindow :: putKaLL()
{
    //customeshape = new CustomeShape;
    customeshapeTemp = new CustomeShape;
    makeCenterX( 0 );
    makeCenterY( 0 );
    scene -> addItem( customeshapeTemp );

}

void MainWindow :: setValue()
{

    if( !wasChangingUsed ){
        ui -> Area -> setText( QString :: number( figure -> Area() ) );
        ui -> Perimeter -> setText( QString :: number ( figure -> Perimeter() ) );
        ui -> CenterMass -> setText("(" + QString::number( figure->getCenter().x()) + ";" + QString::number( figure->getCenter().y()) + ")");
    }else{

        ui -> CenterMass -> setText("(" + QString::number( figure->getCenter().x()) + ";" + QString::number( figure->getCenter().y()) + ")");

    }

}

void MainWindow :: setSliderValue()
{

    this -> ui -> horizontalSliderMoveX -> setValue( 0 );
    this -> ui -> horizontalSliderMoveY -> setValue( 0 );
    this -> ui -> horizontalSliderRotate -> setValue( 0 );
    this -> ui -> horizontalSliderCenterX -> setValue( 0 );
    this -> ui -> horizontalSliderCenterY -> setValue( 0 );
    this -> ui -> horizontalSliderCircleRadius -> setValue( 100 );
    this -> ui -> horizontalSliderCustomSize -> setValue( 1 );
    this -> ui -> horizontalSliderEllipseRadius -> setValue( 100 );
    this -> ui -> horizontalSliderHexagonRadius -> setValue( 100 );
    this -> ui -> horizontalSliderRectangleA -> setValue( 200 );
    this -> ui -> horizontalSliderRectangleB -> setValue( 100 );
    this -> ui -> horizontalSliderSquareA -> setValue( 50 );
    this -> ui -> horizontalSliderTriangleA-> setValue( 50 );
    this -> ui -> horizontalSliderStar5Radius1-> setValue( 50 );
    this -> ui -> horizontalSliderStar5Radius2-> setValue( 50 );
    this -> ui -> horizontalSliderStar6Radius1-> setValue( 50 );
    this -> ui -> horizontalSliderStar6Radius2-> setValue( 50 );
    this -> ui -> horizontalSliderStar8Radius1-> setValue( 50 );
    this -> ui -> horizontalSliderStar8Radius2-> setValue( 50 );
    figure -> makeFlagTrue();

}

void MainWindow :: move_figure_x( int newX )
{

    if( !wasChangingUsed )
    {
        figure -> setX( newX );
        setValue();

    }else
    {

        customeshapeTemp -> setX( newX );

    }



}

void MainWindow :: move_figure_y( int newY )
{

    if( !wasChangingUsed )
    {
        figure -> setY( newY );
        setValue();

    }else
    {

        customeshapeTemp -> setY( newY );

    }



}

void MainWindow :: rotate_figure( int newAngle )
{

    if( !wasChangingUsed )
    {

        figure -> setTransformOriginPoint( QPoint(figure -> getCenter().rx() , figure -> getCenter().ry() ) );
        scene -> update();
        figure -> setRotation( newAngle );
        setValue();

    }else
    {

        customeshapeTemp -> setRotation( newAngle );
        scene -> update();

    }

}

void MainWindow :: makeRadius( int newRadius )
{

    figure -> changeRadius( newRadius );
    scene -> update();
    setValue();

}

void MainWindow :: makeLength( int newLength )
{

    figure -> changeLength( newLength );
    scene -> update();
    setValue();

}

void MainWindow :: makeWidth( int newWidth )
{

    figure -> changeWidth( newWidth );
    scene -> update();
    setValue();

}

void MainWindow :: makeSize( int newSize )
{

    figure -> changeSize( newSize );
    scene -> update();
    setValue();

}

void MainWindow :: makeRadius1( int newRadius1 )
{

    figure -> changeRadius1( newRadius1 );
    scene -> update();
    setValue();

}

void MainWindow :: makeRadius2( int newRadius2 )
{

    figure -> changeRadius2( newRadius2 );
    scene -> update();
    setValue();

}

void MainWindow :: makeCenterX( int newCenterX )
{

    if( !wasChangingUsed )
    {

        figure -> setCenterX( newCenterX );
        scene -> update();

    }else{

        customeshapeTemp -> setCenterX( newCenterX );
        customeshapeTemp -> setTransformOriginPoint( QPoint( customeshapeTemp -> getCenter().rx() , customeshapeTemp -> getCenter().ry() ) );
        scene -> update();

    }

    setValue();

}

void MainWindow :: makeCenterY( int newCenterY )
{

    if( !wasChangingUsed )
    {
        figure -> setCenterY( newCenterY );
        scene -> update();

    }else{

        customeshapeTemp -> setCenterY( newCenterY );
        customeshapeTemp -> setTransformOriginPoint( QPoint( customeshapeTemp -> getCenter().rx() , customeshapeTemp -> getCenter().ry() ) );
        scene -> update();

    }

    setValue();

}

void MainWindow :: makeScale( int newScale )
{


    //customeshape = customeshape + customeshapeTemp;
    //customeshapeTemp = new CustomeShape;
    customeshapeTemp -> changeScale( newScale );
    scene -> update();

}

void MainWindow::onMousePressed(const QPointF &position)
{
    if(wasChangingUsed){

        ui->graphicsView->viewport()->update();
        customeshapeTemp -> pullPoint(position);
        ui->graphicsView->viewport()->update();

    }
}

