#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    eyes = new Eyes();
    mouth = new Mouth();

    ui ->graphicsView ->setScene(scene);
    QGraphicsEllipseItem *contur = scene->addEllipse(15, 0, 400, 400);
    QPen pen;
    pen.setWidth(9); // толщина контура
    pen.setColor(QColor(255, 220, 9)); // цвет контура
    contur->setPen(pen);

    QGraphicsEllipseItem *eye1 = scene->addEllipse(90,120,100,60);
    pen.setWidth(1);
    pen.setColor(QColor(255, 210, 9));
    eye1->setPen(pen);
    QGraphicsEllipseItem *eye2 = scene->addEllipse(250,120,100,60);
    eye2->setPen(pen);

    QGraphicsEllipseItem *moutho1 = scene->addEllipse(160,250,120,40);
    pen.setColor(QColor(208, 20, 9)); // цвет контура
    moutho1->setPen(pen);

    QGraphicsEllipseItem *moutho2 = scene->addEllipse(165,257,110,25);


    // Установка цвета заливки овалов
    contur->setBrush(QColor(252, 226, 5));

    eye1->setBrush(Qt::white);
    eye2->setBrush(Qt::white);

    moutho1->setBrush(QColor(208, 20, 9));

    moutho2->setBrush(Qt::black);

    scene->addItem(eyes);
    scene->addLine(168, 270, 271, 270, QPen(Qt::black, 3));

    scene->addItem(mouth);
}

MainWindow::~MainWindow()
{
    delete ui;
}



