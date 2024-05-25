#include "ship.h"

Ship::Ship(QWidget *parent)
    : QWidget{}
{
    this->setParent(parent);
}


void Ship::paintEvent(QPaintEvent *event) {
    QPainter *painter = new QPainter;
    painter->begin(this);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::gray);
    QPolygon ship;
    ship << QPoint(100, 400) << QPoint(200, 500) << QPoint(500, 500) << QPoint(600, 400);
    painter->drawPolygon(ship);
    painter->drawLine(QPoint(350, 400), QPoint(350, 100));
    painter->end();
}
