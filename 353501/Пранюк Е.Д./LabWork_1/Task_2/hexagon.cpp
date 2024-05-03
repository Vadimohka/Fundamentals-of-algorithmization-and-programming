#include "hexagon.h"

Hexagon::Hexagon() {}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget ){
    //QPainter painter(this);
    painter->setBrush(Qt::NoBrush);
    painter->setPen(QPen(QColorConstants::Svg::pink, Figure::k));
    double r = sqrt(pow(Figure::startPoint.x() - Figure::endPoint.x(), 2) + pow(Figure::startPoint.y() - Figure::endPoint.y(), 2));
    QPolygonF polygon;
    for (int i = 0; i < 6; i++){
        polygon << QPointF(r * cos( i * M_PI / 3) + Figure::startPoint.x(), r * sin( i * M_PI / 3) + Figure::startPoint.y());
    }
    painter->drawPolygon(polygon);
}

float Hexagon::perimeter()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())+qAbs(Figure::endPoint.x()-Figure::startPoint.x()))*2;
}

float Hexagon::area()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())*qAbs(Figure::endPoint.x()-Figure::startPoint.x()));
}
