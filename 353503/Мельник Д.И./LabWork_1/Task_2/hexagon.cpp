#include "hexagon.h"
#include <QPainter>

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
    painter->setPen(QPen(Qt::black, 2));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() - startPoint().x()) / 4, startPoint().y())
            << QPointF(startPoint().x() + ((endPoint().x() - startPoint().x()) / 4) * 3, startPoint().y())
            << QPointF(endPoint().x(), endPoint().y() - (endPoint().y() - startPoint().y()) / 2)
            << QPointF(startPoint().x() + ((endPoint().x() - startPoint().x()) / 4) * 3,endPoint().y())
            << QPointF(startPoint().x() + (endPoint().x() - startPoint().x()) / 4, endPoint().y())
            << QPointF(startPoint().x(), endPoint().y() - (endPoint().y() - startPoint().y()) / 2);

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

double Hexagon::area() {
    double triangleHeight = (endPoint().y() - startPoint().y()) / 2;
    double triangleBase = (endPoint().x() - startPoint().x()) / 4;
    double rectangleHeight = triangleHeight;
    double rectangleWidth = triangleBase * 2;

    double triangleArea = (triangleBase * triangleHeight) / 2;
    double rectangleArea = rectangleHeight * rectangleWidth;

    return abs(2 * triangleArea + rectangleArea);
}

double Hexagon::perimeter() {
    double sideLength = (endPoint().x() - startPoint().x()) / 4;
    return abs(6 * sideLength);
}

