#include "mainwindow.h"
#include "balloon.h"

#include <QApplication>
#include <QWidget>

class MyWidget : public QWidget
{
    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        QPen pen(Qt::black, 10, Qt::SolidLine);
        painter.setPen(pen);
        pen.setWidth(5);
        painter.drawLine(150,700,150,1000);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;
    QGraphicsView *view = new QGraphicsView(&window);
    QGraphicsScene *scene = new QGraphicsScene();
    view->setScene(scene);
    QGraphicsLineItem* line = new QGraphicsLineItem(150,700,150,250);
    scene->addItem(line);
    balloon *myballoon = new balloon();
    scene->addItem(myballoon);
    window.setCentralWidget(view);

    QPushButton *popButton = new QPushButton("Pop");
    popButton->setParent(view);
    popButton->move(50,50);
    popButton->show();
    QObject::connect(popButton, &QPushButton::clicked, myballoon, &movingellipse::pop);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setSceneRect(0, 0, 300, 300);
    window.show();
    return a.exec();
}
