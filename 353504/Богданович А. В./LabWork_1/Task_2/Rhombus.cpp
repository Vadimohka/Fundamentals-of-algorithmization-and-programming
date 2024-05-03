#include "Rhombus.h"
//#include <cmath>

Rhombus::Rhombus()
{

}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon rhombus;
    rhombus << QPoint(-a/2, 0) << QPoint(0, -b/2) << QPoint(a/2, 0) << QPoint(0, b/2);
    painter->drawPolygon(rhombus);
}

float Rhombus::findArea() {
    float s = this->getScale();
    return a*b*s*s/2;
}

float Rhombus::findPerimeter()
{
    float s = this->getScale();
    return s*4*sqrt(a*a/4+b*b/4);
}

void Rhombus::setAB(int a, int b)
{
    this->a = a;
    this->b = b;
}

int Rhombus::getA()
{
    return this->a;
}

int Rhombus::getB() {
    return this->b;
}
