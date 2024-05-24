#include "trapezoid.h"

Trapezoid::Trapezoid(){

}
void Trapezoid::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << QPoint(-70,40) << QPoint(-40,-40) << QPoint(60,-40) << QPoint(90, 40);
    painter->drawPolygon(polygon);
}

float Trapezoid::area(){
    return (this->getScale() * this->getScale() * h * (b+c) / 2);
}

float Trapezoid::perimeter(){
    return (this->getScale() * (b + c + 2*h*qSqrt(2)));
}
