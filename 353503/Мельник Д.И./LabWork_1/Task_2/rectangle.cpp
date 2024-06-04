#include "rectangle.h"
#include <QPainter>

Rectangle::Rectangle(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Rectangle::~Rectangle()
{

}

// Реализуем метод отрисовки
void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x(), endPoint().y())
            << QPointF(endPoint().x(), endPoint().y())
            << QPointF(endPoint().x(), startPoint().y())
            << QPointF(startPoint().x(),startPoint().y());

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
double Rectangle::area(){
    return abs((endPoint().x() - startPoint().x()) * (endPoint().y() - startPoint().y()));
}

double Rectangle::perimeter(){
    return abs((endPoint().x() - startPoint().x()) * 2 + (endPoint().y() - startPoint().y()) * 2);
}
