#include "parallelohram.h"

Parallelohram::Parallelohram()
{

}
void Parallelohram::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << QPoint(-80,40) << QPoint(-30,-40) << QPoint(70,-40) << QPoint(20, 40);
    painter->drawPolygon(polygon);
}

float Parallelohram::area()
{
    return this->getScale() * this->getScale() * sin(32*M_PI/180) * b * c;
}

float Parallelohram::perimeter(){
    return (2 * getScale() * b + 2 * getScale() * c);
}
