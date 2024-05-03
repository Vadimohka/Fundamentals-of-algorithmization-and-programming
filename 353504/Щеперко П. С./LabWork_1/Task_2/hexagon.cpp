#include "hexagon.h"

Hexagon::Hexagon() {}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon hex;
    hex << QPoint(-r,0) << QPoint(-r / 2, r * sqrt(3) / 2)
        << QPoint(r / 2,r * sqrt(3) / 2) << QPoint(r,0)
        << QPoint(r / 2,-r * sqrt(3) / 2) << QPoint(-r/2,-r * sqrt(3)/2);
    painter->drawPolygon(hex);
}

float Hexagon::findArea()
{
    float s = this->getScale();
    return s*s*3*r*r*sqrt(3)/2;
}

float Hexagon::findPerimeter()
{
    float s = this->getScale();
    return 6*r*s;
}

void Hexagon::setR(int r) {
    this->r = r;
}

int Hexagon::getR() {
    return this->r;
}
