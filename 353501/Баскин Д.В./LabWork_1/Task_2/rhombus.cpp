#include "rhombus.h"

Rhombus::Rhombus()
{

}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << QPoint(0, -width / 2) << QPoint(-length / 2, 0) << QPoint(0, width / 2) << QPoint(length / 2, 0);
    painter->drawPolygon(polygon);
}

float Rhombus::area()
{
    return this->getScale() * this->getScale() * length * width / 2;
}

float Rhombus::perimeter()
{
    return this->getScale() * 4 * sqrt(length * length / 4 + width * width / 4);
}

void Rhombus::setLength(int value)
{
    this->length = value;
    update();
}

void Rhombus::setWidth(int value)
{
    this->width = value;
    update();
}


float Rhombus::getLength()
{
    return this->length;
}

float Rhombus::getWidth()
{
    return this->width;
}
