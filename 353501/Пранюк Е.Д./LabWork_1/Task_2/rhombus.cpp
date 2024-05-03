#include "rhombus.h"

Rhombus::Rhombus() {}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(QColorConstants::Svg::pink, Figure::k));

    int x1 = (Figure::startPoint.x() + Figure::endPoint.x()) / 2;
    int y1 = Figure::startPoint.y();
    QPoint p1(x1, y1);

    int x2 = Figure::startPoint.x();
    int y2 = (Figure::startPoint.y() + Figure::endPoint.y())/2;
    QPoint p2 (x2, y2);

    int x3 = (Figure::startPoint.x() + Figure::endPoint.x()) / 2;
    int y3 = Figure::endPoint.y();
    QPoint p3(x3, y3);

    int x4 = Figure::endPoint.x();
    int y4 = (Figure::startPoint.y() + Figure::endPoint.y())/2;
    QPoint p4(x4, y4);

    QPolygon pol;
    pol<<QPoint(p1)<<QPoint(p2)<<QPoint(p3)<<QPoint(p4)<<QPoint(p1);
    painter->drawPolygon(pol);

    painter->setBrush(Qt::red);
    //painter->drawEllipse((Figure::startPoint.x() + Figure::endPoint.x()) / 2, (Figure::startPoint.y() + Figure::endPoint.y()) / 2, 10,10);
}

float Rhombus::perimeter()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())+qAbs(Figure::endPoint.x()-Figure::startPoint.x()))*2;
}

float Rhombus::area()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())*qAbs(Figure::endPoint.x()-Figure::startPoint.x()));
}
