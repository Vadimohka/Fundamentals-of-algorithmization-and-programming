#include "triangle.h"

Triangle::Triangle() {}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << QPoint(0, -a/3*sqrt(3)) << QPoint(a*2/3, a/3*sqrt(3)) << QPoint(-a*2/3, a/3*sqrt(3));
    painter->drawPolygon(polygon);
}

float Triangle::findArea()
{
    float s = this->getScale();
    return s*s*a*a*sqrt(3)/4;
}

float Triangle::findPerimeter()
{
    float s = this->getScale();
    return 3*a*s;
}

void Triangle::setA(int a) {
    this->a = a;
}

int Triangle::getA() {
    return this->a;
}
