#include "mainwindow.h"

MainWindow::MainWindow(QWidget*parent)
    : QMainWindow(parent){

    this->resize(2000,300);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,2000,200);

    QGraphicsView *view = new QGraphicsView(scene);
    this->setCentralWidget(view);

    circleRotate = new CircleRotation;
    QGraphicsEllipseItem *item = new QGraphicsEllipseItem;
    item->setRect(0, 0, 100, 100);
    circleRotate->setPos(0,0);
    scene->addItem(circleRotate);

    QPushButton *button = new QPushButton("START/STOP", this);

    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout,this, &MainWindow::movingCircle);
    timer->start(20);
    connect(button,&QPushButton::clicked,circleRotate, &CircleRotation::turnOn);
    connect(button,&QPushButton::clicked,circleRotate, &CircleRotation::pushOn);
}

MainWindow::~MainWindow(){

}

void MainWindow::movingCircle(){
    circleRotate->move();
    scene->update();
}
