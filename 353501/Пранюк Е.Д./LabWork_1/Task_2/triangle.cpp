#include "triangle.h"

Triangle::Triangle() {}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(QPen(QColorConstants::Svg::pink, Figure::k));

    int topX = (Figure::startPoint.x() + Figure::endPoint.x()) / 2;
    int topY = Figure::endPoint.y();
    QPointF topPoint(topX, topY);

    int bottomX = Figure::endPoint.x();
    int bottomY = Figure::startPoint.y();
    QPointF bottomPoint (bottomX, bottomY);

    QPolygonF pol;
    pol<<QPointF(Figure::startPoint)<<QPointF(topPoint)<<QPointF(bottomPoint);
    painter->drawPolygon(pol);
    painter->setBrush(Qt::red);
    //painter->drawEllipse((Figure::startPoint.x() + Figure::endPoint.x()) / 2, (Figure::startPoint.y() + Figure::endPoint.y()) / 2+50, 10,10);
}

float Triangle::perimeter()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())+qAbs(Figure::endPoint.x()-Figure::startPoint.x()))*2;
}

float Triangle::area()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())*qAbs(Figure::endPoint.x()-Figure::startPoint.x()));
}
