#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui -> graphicsView -> setScene( scene );
    //circle = new Circle( 200 , 200 , 100 , 100 );
    //scene -> addItem( circle );
    wheel = new Wheel( 200 , 200 , 100 , 100 );
    scene -> addItem( wheel );
    slider = new QSlider;
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(0, 400);
    slider->setValue(200);
    slider->setGeometry( 50 , 400 , 400 , 30 );
    scene -> addWidget( slider );
    connect( slider , SIGNAL( valueChanged(int) ) , wheel , SLOT ( move(int) )  );
    connect( slider , SIGNAL( valueChanged(int) ) , this , SLOT ( updateScene() )  );
    connect( slider , SIGNAL( valueChanged(int) ) , wheel , SLOT ( rotate(int) )  );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: updateScene()
{

    scene -> update();

}
