#include "plane.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;
    QGraphicsView *view = new QGraphicsView(&window);
    QGraphicsScene *scene = new QGraphicsScene();
    view->setScene(scene);
    Plane *plane = new Plane();
    scene->addItem(plane);
    window.setCentralWidget(view);
    QDockWidget *dock = new QDockWidget("Controls", &window);
    window.addDockWidget(Qt::RightDockWidgetArea, dock);
    QPushButton *moveLeftButton = new QPushButton("Move Left");
    QPushButton *moveRightButton = new QPushButton("Move Right");
    QPushButton *moveUpButton = new QPushButton("Move Up");
    QPushButton *moveDownButton = new QPushButton("Move Down");
    QPushButton *lowergearb = new QPushButton("Lower landing gear");
    QPushButton *unlowergearb = new QPushButton("Unlower landing gear");
    QObject::connect(moveLeftButton, &QPushButton::clicked, plane, &Plane::moveLeft);
    QObject::connect(moveRightButton, &QPushButton::clicked, plane, &Plane::moveRight);
    QObject::connect(moveUpButton, &QPushButton::clicked, plane, &Plane::moveUp);
    QObject::connect(moveDownButton, &QPushButton::clicked, plane, &Plane::moveDown);
    QObject::connect(lowergearb, &QPushButton::clicked, plane, &Plane::lowerGear);
    QObject::connect(unlowergearb, &QPushButton::clicked, plane, &Plane::unLowerGear);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(moveLeftButton);
    vbox->addWidget(moveRightButton);
    vbox->addWidget(moveUpButton);
    vbox->addWidget(moveDownButton);
    vbox->addWidget(lowergearb);
    vbox->addWidget(unlowergearb);
    QWidget *widget = new QWidget;
    widget->setLayout(vbox);
    dock->setWidget(widget);
    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setSceneRect(-200, -200, 400, 400);
    window.show();
    return a.exec();
}
