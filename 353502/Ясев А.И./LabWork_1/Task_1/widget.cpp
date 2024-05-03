#include "widget.h"
#include "ui_widget.h"
#include "wheel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setSceneRect(0,0,ui->graphicsView->width(), ui->graphicsView->height());
    scene->setSceneRect(ui->graphicsView->sceneRect());
    ui->graphicsView->setScene(scene);
    scene->addRect(0,scene->height()/2,scene->width(),scene->height()/2,QPen(QColor(0,0,0,0)),QBrush(QColor(0,255,0)));
    scene->addRect(0,0,scene->width(),scene->height()/2,QPen(QColor(0,0,0,0)),QBrush(QColor(100,150,255)));

    Wheel *wheel = new Wheel(scene);
    scene->addItem(wheel);
    connect(ui->leftButton, SIGNAL(clicked(bool)), wheel, SLOT(moveLeft()));
    connect(ui->rightButton, SIGNAL(clicked(bool)),wheel, SLOT(moveRight()));

//     MovingCircle *circle = new MovingCircle(scene);
//     scene->addItem(circle);
//     connect(ui->leftButton, SIGNAL(clicked(bool)),circle, SLOT(moveLeft()));
//     connect(ui->rightButton, SIGNAL(clicked(bool)),circle, SLOT(moveRight()));
 }

Widget::~Widget()
{
    delete ui;
}
