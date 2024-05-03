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

    QRectF rect(qMin(endPoint().x(), startPoint().x()),
                qMin(endPoint().y(), startPoint().y()),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));
    
    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}


double Rectangle::Ploshad(){
    return qAbs((startPoint().x()-endPoint().x())*(startPoint().y()-endPoint().y()));
}

double Rectangle::Perimeter(){
    return (qAbs(startPoint().x()-endPoint().x())+qAbs(startPoint().y()-endPoint().y()))*2;
}