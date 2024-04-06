#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), scene(new QGraphicsScene(this)), leftWheel(new QGraphicsEllipseItem()), rightWheel(new QGraphicsEllipseItem()), leftButton(new QPushButton("Left")), rightButton(new QPushButton("Right"))
{
    wagon = new Wagon(leftWheel, rightWheel);
    wagon->setRect(0, 0, 100, 50);
    leftWheel->setRect(-10, 40, 30, 30);
    rightWheel->setRect(80, 40, 30, 30);
    QGraphicsLineItem* rail = new QGraphicsLineItem();
    rail->setLine(0, 350, 800, 350);
    rail->setPen(QPen(Qt::black, 5));

    QBrush brush(Qt::black);
    leftWheel->setBrush(brush);
    rightWheel->setBrush(brush);
    QBrush brush2(Qt::gray);
    wagon->setBrush(brush2);
    scene->addItem(wagon);
    scene->addItem(leftWheel);
    scene->addItem(rightWheel);
    scene->addItem(rail);

    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);
    view->setSceneRect(0, 0, 800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    wagon->setFlag(QGraphicsItem::ItemIsFocusable);
    wagon->setFocus();

    connect(leftButton, &QPushButton::clicked, this, [this] { this->moveWagon(-10); });
    connect(rightButton, &QPushButton::clicked, this, [this] { this->moveWagon(10); });

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(leftButton);
    layout->addWidget(view);
    layout->addWidget(rightButton);

    QWidget *window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);

    int initialX = (view->width() - wagon->rect().width()) / 2;
    int initialY = (view->height() - wagon->rect().height()) / 2;
    wagon->setPos(initialX, initialY);
    leftWheel->setPos(initialX, initialY + 5);
    rightWheel->setPos(initialX + 5, initialY + 5);
}

void MainWindow::moveWagon(int dx) {
    int newX = wagon->x() + dx;
    if (newX < 0 || newX + wagon->rect().width() > 800) {
        return;
    }
    wagon->setPos(wagon->x()+dx, wagon->y());
    leftWheel->setPos(leftWheel->x()+dx, leftWheel->y());
    rightWheel->setPos(rightWheel->x()+dx, rightWheel->y());
}

MainWindow::~MainWindow()
{
    delete scene;
    delete wagon;
    delete leftButton;
    delete rightButton;
}
