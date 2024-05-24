#include "hexagon.h"

Hexagon::Hexagon(){

}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << QPoint(-radius,0) << QPoint(-radius / 2, radius * sqrt(3) / 2) << QPoint(radius / 2,radius * sqrt(3) / 2) << QPoint(radius,0) << QPoint(radius / 2,-radius * sqrt(3) / 2) << QPoint(-radius/2,-radius * sqrt(3)/2);
    painter->drawPolygon(polygon);
}

float Hexagon::area(){
    return this->getScale() * this->getScale() * 3 * radius * radius * sqrt(3) / 2;
}

float Hexagon::perimeter(){
    return 6 * radius * this->getScale();
}
