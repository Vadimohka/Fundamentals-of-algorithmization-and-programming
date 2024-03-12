
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

    QRectF rect(qMin(endPoint().x(), startPoint().x()),
                qMin(endPoint().y(), startPoint().y()),
                qMin(qAbs(endPoint().x() - startPoint().x()),qAbs(endPoint().y() - startPoint().y())),
                qMin(qAbs(endPoint().x() - startPoint().x()),qAbs(endPoint().y() - startPoint().y())));
    
    painter->drawEllipse(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

double Circle::Ploshad(){
    return qAbs((startPoint().x()-endPoint().x()))*M_PI/2;
}

double Circle::Perimeter(){
    return qAbs(startPoint().x()-endPoint().x())*M_PI;
}