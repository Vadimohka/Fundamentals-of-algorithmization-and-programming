#include "circle.h"
#include <QPainter>

Circle::Circle(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Circle::~Circle()
{

}

// Реализуем метод отрисовки
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));
    if (endPoint().x() < endPoint().y())
        endPoint().rx() = endPoint().ry();

    painter->drawEllipse(startPoint().x(),startPoint().y(),endPoint().x() - startPoint().x(),endPoint().x() - startPoint().x());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

double Circle::area() {
    double radius = (endPoint().x() - startPoint().x()) / 2;
    return abs(M_PI * pow(radius, 2));
}

double Circle::perimeter() {
    double radius = (endPoint().x() - startPoint().x()) / 2;
    return abs(2 * M_PI * radius);
}
