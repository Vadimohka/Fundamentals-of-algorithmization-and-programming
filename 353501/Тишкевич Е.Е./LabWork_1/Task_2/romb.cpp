#include "romb.h"

Romb::Romb(){}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygonF polygon;
    polygon << QPointF(0,-150*scale*widS) << QPointF(75*scale*heiS,0) << QPointF(0,150*scale*widS) << QPointF(-75*scale*heiS,0);
    painter->drawPolygon(polygon);
    painter->setPen(QPen(Qt::red, 3));
    QPointF localPoint(x, y);
    painter->drawPoint(localPoint);
    painter->setPen(QPen(Qt::darkGreen, 3));
    painter->drawPoint(0,0);
    painter->setPen(Qt::black);
}

float Romb::perim()
{
    return 4 * getScale() * len*widS;
}

float Romb::area()
{
    return len*widS * len*heiS * sin(60 * M_PI / 180) * this->getScale() * this->getScale();
}

float Romb::getDiam1() {return heiS;}

float Romb::getDiam2() {return widS;}

void Romb::setDiam1(float num) {heiS=num;}

void Romb::setDiam2(float num) {widS=num;}
