#include "rectangle.h"

Rectangle::Rectangle() {}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(QPen(QColorConstants::Svg::pink, Figure::k));
    painter->drawRect(QRectF(Figure::startPoint, Figure::endPoint));
    painter->setBrush(Qt::red);
    //painter->drawEllipse((Figure::startPoint.x() + Figure::endPoint.x()) / 2, (Figure::startPoint.y() + Figure::endPoint.y()) / 2, 10,10);
}

void Rectangle::setRotation(int angle){

}

float Rectangle::perimeter()
{
     return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())+qAbs(Figure::endPoint.x()-Figure::startPoint.x()))*2;
}

float Rectangle::area()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())*qAbs(Figure::endPoint.x()-Figure::startPoint.x()));
}
