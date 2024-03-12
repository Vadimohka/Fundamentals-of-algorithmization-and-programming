#include "triangle.h"
#include <QPainter>
#include "figure.h"


Triangle::Triangle(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Triangle::~Triangle()
{

}

// Реализуем метод отрисовки
void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), startPoint().y())
                << QPointF((endPoint().x() > startPoint().x()) ? endPoint().x() : startPoint().x(),
                           endPoint().y())
                << QPointF((endPoint().x() > startPoint().x()) ? startPoint().x() : endPoint().x(),
                           endPoint().y());

    painter->drawPolygon(polygon);

    QPointF point = (startPoint()+endPoint())/2;
    painter->drawEllipse(point.x(), point.y(), 10, 10);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}


double Triangle::Ploshad(){
    return qAbs((startPoint().x()-endPoint().x())*(startPoint().y()-endPoint().y())/2);
}

double Triangle::Perimeter(){
    return qAbs(startPoint().x()-endPoint().x())*3;
}

// void Triangle::paintPoint()
// {
//     QPointF point = (startPoint()+endPoint())/2;
//     ->drawEllipse(point.x(), point.y(), 10, 10);
// }