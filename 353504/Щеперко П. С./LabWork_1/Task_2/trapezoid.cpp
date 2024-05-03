#include "trapezoid.h"

Trapezoid::Trapezoid() {}

void Trapezoid::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon trapezoid;
    trapezoid << QPoint(-a/2, -h/2) << QPoint(a/2, -h/2) << QPoint(b/2, h/2) << QPoint(-b/2, h/2);
    painter->drawPolygon(trapezoid);
}

float Trapezoid::findArea()
{
    float s = this->getScale();
    return s*s*(a+b)*h/2;
}

float Trapezoid::findPerimeter()
{
    float s = this->getScale();
    return s*(a + b + 2*sqrt(h*h + (a-b)*(a-b)/4));
}

void Trapezoid::setABH(int a, int b, int h) {
    this->a = a;
    this->b = b;
    this->h = h;
}

int Trapezoid::getA() {
    return this->a;
}

int Trapezoid::getB() {
    return this->b;
}

int Trapezoid::getH(){
    return this->h;
}
