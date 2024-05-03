#include "square.h"

Square::Square() {}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QPainter painter(this);
    painter->setPen(QPen(QColorConstants::Svg::pink, Figure::k));
    painter->drawRect(Figure::startPoint.x(), Figure::startPoint.y(),
                     std::min(Figure::endPoint.x()-Figure::startPoint.x(), Figure::endPoint.y()-Figure::startPoint.y()),
                     std::min(Figure::endPoint.x()-Figure::startPoint.x(), Figure::endPoint.y()-Figure::startPoint.y()));
    painter->setBrush(Qt::red);
   // painter->drawEllipse((Figure::startPoint.x() + Figure::endPoint.x()) / 2, (Figure::startPoint.y() + Figure::endPoint.y()) / 2, 10,10);
}

float Square::perimeter()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())+qAbs(Figure::endPoint.x()-Figure::startPoint.x()))*2;
}

float Square::area()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())*qAbs(Figure::endPoint.x()-Figure::startPoint.x()));
}
