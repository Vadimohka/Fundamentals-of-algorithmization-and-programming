#include "square.h"
#include <QPainter>

Square::Square(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Square::~Square()
{

}

// Реализуем метод отрисовки
void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    if(endPoint().x() > endPoint().y())
        endPoint().rx() = endPoint().ry();
    painter->drawRect(startPoint().x(), startPoint().y(), endPoint().x() - startPoint().x(), endPoint().x() - startPoint().x());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

double Square::area(){
    return abs((endPoint().x() - startPoint().x()) * (endPoint().y() - startPoint().y()));
}

double Square::perimeter(){
    return abs((endPoint().x() - startPoint().x()) * 2 + (endPoint().y() - startPoint().y()) * 2);
}
