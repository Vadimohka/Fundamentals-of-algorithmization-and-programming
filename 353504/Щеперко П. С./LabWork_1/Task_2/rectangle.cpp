#include "rectangle.h"

Rectangle::Rectangle() {}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawRect(-a/2, -b/2, a, b);
}

float Rectangle::findArea()
{
    float s = this->getScale();
    return s*s*a*b;
}

float Rectangle::findPerimeter()
{
    float s = this->getScale();
    return s*2*(a+b);
}

void Rectangle::setAB(int a, int b) {
    this->a = a;
    this->b = b;
}

int Rectangle::getA() {
    return this->a;
}

int Rectangle::getB()
{
    return this->b;
}
