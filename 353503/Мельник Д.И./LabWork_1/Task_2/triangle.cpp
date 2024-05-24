#include "triangle.h"
#include <QPainter>

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

    polygon << QPointF(startPoint().x(), startPoint().y())
            << QPointF(startPoint().x() - (endPoint().x() - startPoint().x()), endPoint().y())
            << QPointF(endPoint().x(), endPoint().y());

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

double Triangle::area() {
    double base = abs(endPoint().x() - startPoint().x());
    double height = abs(endPoint().y() - startPoint().y());
    return abs(0.5 * base * height);
}

double Triangle::perimeter() {
    double base = abs(endPoint().x() - startPoint().x());
    double height = abs(endPoint().y() - startPoint().y());
    double hypotenuse = sqrt(pow(base, 2) + pow(height, 2));
    return abs(base + height + hypotenuse);
}

