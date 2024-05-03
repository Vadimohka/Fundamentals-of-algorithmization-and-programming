#include "rhomb.h"

Rhomb::Rhomb() {}

void Rhomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon rhombus;
    rhombus << QPoint(-a/2, 0) << QPoint(0, -b/2) << QPoint(a/2, 0) << QPoint(0, b/2);
    painter->drawPolygon(rhombus);
}

float Rhomb::findArea() {
    float s = this->getScale();
    return a*b*s*s/2;
}

float Rhomb::findPerimeter()
{
    float s = this->getScale();
    return s*4*sqrt(a*a/4+b*b/4);
}

void Rhomb::setAB(int a, int b)
{
    this->a = a;
    this->b = b;
}

int Rhomb::getA()
{
    return this->a;
}

int Rhomb::getB() {
    return this->b;
}
