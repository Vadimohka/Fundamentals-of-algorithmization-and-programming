#include "rhombus.h"

Rhombus::Rhombus()
{

}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << QPoint(0,-40) << QPoint(25,0) << QPoint(0,40) << QPoint(-25,0);
    painter->drawPolygon(polygon);
}

float Rhombus::area()
{
    return size * size * sin(64 * M_PI / 180) * this->getScale() * this->getScale();
}

float Rhombus::perimeter()
{
    return 4 * getScale() * size;
}
