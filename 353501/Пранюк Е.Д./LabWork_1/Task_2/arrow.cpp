#include "arrow.h"

Arrow::Arrow() {}

void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::red, Figure::k));
    QPolygonF arrow;
    arrow<<Figure::startPoint<< Figure::endPoint<<QPointF(Figure::endPoint.x(),Figure::endPoint.y()/4)
          <<QPointF((Figure::endPoint.x()-Figure::endPoint.x()*3/4),Figure::endPoint.y());
    painter->drawPolygon(arrow);
}

float Arrow::perimeter()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())+qAbs(Figure::endPoint.x()-Figure::startPoint.x()))*2;
}
