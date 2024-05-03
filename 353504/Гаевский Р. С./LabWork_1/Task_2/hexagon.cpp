#include "hexagon.h"

Hexagon::Hexagon()
{

}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);
    QPolygon polygon;
    polygon << QPoint(-radius,0) << QPoint(-radius / 2, radius * sqrt(3) / 2) << QPoint(radius / 2,radius * sqrt(3) / 2) << QPoint(radius,0) << QPoint(radius / 2,-radius * sqrt(3) / 2) << QPoint(-radius/2,-radius * sqrt(3)/2);
    painter->drawPolygon(polygon);
}
void Hexagon::updateSizeRadiushaha(double arg1){
    radius=arg1;

}
float Hexagon::area()
{
    return this->getScale() * this->getScale() * 3 * radius * radius * sqrt(3) / 2;
}

float Hexagon::perimeter()
{
    return 6 * radius * this->getScale();
}
