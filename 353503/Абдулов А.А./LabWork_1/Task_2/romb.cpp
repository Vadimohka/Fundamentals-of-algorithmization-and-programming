#include "romb.h"

Romb::Romb(){

}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << QPoint(0,-80) << QPoint(60,0) << QPoint(0,80) << QPoint(-60,0);
    painter->drawPolygon(polygon);
}

float Romb::area(){
    return (this->getScale() * this->getScale() * 2 * 60 * 80);
}

float Romb::perimeter(){
    return 4 * getScale() * size;
}
