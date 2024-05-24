#include "ellipse.h"
#include <QPainter>

Ellipse::Ellipse(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Ellipse::~Ellipse()
{

}

// Реализуем метод отрисовки
void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    painter->drawEllipse(startPoint().x(),startPoint().y(),endPoint().x() - startPoint().x(),endPoint().y() - startPoint().y());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

double Ellipse::area() {
    double a = (endPoint().x() - startPoint().x()) / 2;
    double b = (endPoint().y() - startPoint().y()) / 2;
    return abs(M_PI * a * b);
}

double Ellipse::perimeter() {
    double a = (endPoint().x() - startPoint().x()) / 2;
    double b = (endPoint().y() - startPoint().y()) / 2;
    return abs(2 * M_PI * sqrt((pow(a, 2) + pow(b, 2)) / 2));
}

