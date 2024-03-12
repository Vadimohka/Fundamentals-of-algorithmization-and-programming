#include "hexagon.h"
#include <QPainter>
#include <cmath>
#include <qnamespace.h>


Hexagon::Hexagon(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Hexagon::~Hexagon()
{

}

// Реализуем метод отрисовки
void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::NoBrush);
    painter->setPen(QPen(Qt::black, 2));
    double r = sqrt(pow(startPoint().x() - endPoint().x(), 2) + pow(startPoint().y() - endPoint().y(), 2));
    QPolygonF polygon;
    for (int i = 0; i < 6; i++){
        polygon << QPointF(r * cos( i * M_PI / 3) + startPoint().x(), r * sin( i * M_PI / 3) + startPoint().y());
    }
    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}


double Hexagon::Ploshad(){
    return qAbs((startPoint().x()-endPoint().x())*(startPoint().y()-endPoint().y()));
}

double Hexagon::Perimeter(){
    return (qAbs(startPoint().x()-endPoint().x())+qAbs(startPoint().y()-endPoint().y())*2*1.73);
}