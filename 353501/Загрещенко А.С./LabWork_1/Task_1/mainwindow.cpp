#include "mainwindow.h"
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QTimer"
#include "QPushButton"
#include "QEvent"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1800, 1200);
    scene = new MyScene(this);
    scene->setSceneRect(0, 0, 1800, 1200);

    QGraphicsView *view = new QGraphicsView(scene);
    this->setCentralWidget(view);

    QPushButton *button = new QPushButton("Start/Stop", this);

    movCart = new MovingCart;
    movCart->setPos(50, 200);

    scene->addItem(movCart);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveObject);
    timer->start(10);

    connect(button, &QPushButton::clicked, movCart, &MovingCart::turnOnMove);
}

MainWindow::~MainWindow()
{

}

void MainWindow::moveObject()
{
    movCart->move();

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    MovingCart *movCart = new MovingCart;
    movCart->setPos(event->scenePosition());
    scene->addItem(movCart);
    qDebug() << "AAA";
}

void MainWindow::SlotMouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "Artem";
}





