#include "square.h"

Square::Square() {}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawRect(-a/2, -a/2, a, a);
}

float Square::findArea()
{
    float s = this->getScale();
    return s*s*a*a;
}

float Square::findPerimeter()
{
    float s = this->getScale();
    return s*4*a;
}

void Square::setA(int a) {
    this->a = a;
}

int Square::getA() {
    return this->a;
}
