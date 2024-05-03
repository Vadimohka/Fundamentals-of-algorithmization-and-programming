#include "triangle.h"

Triangle::Triangle(){}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << Fpoint*scale << Spoint*scale << Tpoint*scale;
    painter->drawPolygon(polygon);
    painter->setPen(QPen(Qt::red, 3));
    painter->drawPoint(0,0);
    painter->setPen(Qt::black);
}

float Triangle::area()
{
    return this->getScale() * this->getScale() * (size*size*sqrt(3)) / 4;
}

float Triangle::perim()
{
    return 3 * size * this->getScale();
}

float Triangle::getS1() {return s1;}

void Triangle::setS1(float num) {s1=num;}
