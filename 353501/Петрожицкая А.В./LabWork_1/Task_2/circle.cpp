#include "circle.h"

Circle::Circle() {}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ){
    painter->setPen(QPen(QColorConstants::Svg::pink, 2));
    painter->drawEllipse(startPoint.x(), startPoint.y(),
                         std::min(endPoint.x()-startPoint.x(), endPoint.y()-startPoint.y()),
                         std::min(endPoint.x()-startPoint.x(), endPoint.y()-startPoint.y()));

}

float Circle::perimeter()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())+qAbs(Figure::endPoint.x()-Figure::startPoint.x()))*M_PI;
}

float Circle::area()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())*qAbs(Figure::endPoint.x()-Figure::startPoint.x())*M_PI);
}

float Circle::centerY(){
    return(qAbs(Figure::endPoint.y()-Figure::startPoint.y())/2);
}

float Circle::centerX(){
    return(qAbs(Figure::endPoint.x()-Figure::startPoint.x())/2);
}
