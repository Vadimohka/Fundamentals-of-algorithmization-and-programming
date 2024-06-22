#include "myqgraphicsview.h"

MyQGraphicsView::MyQGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    this->setSceneRect(50, 50, 350, 350);
    this->setScene(scene);
}

void MyQGraphicsView::mousePressEvent(QMouseEvent* event)
{
    QPointF pt = mapToScene(event->pos());
    scene->addEllipse(pt.x(), pt.y(), 100, 100);
    qDebug() << "cerb4eb";

}
