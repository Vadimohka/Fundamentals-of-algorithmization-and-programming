#include "painting.h"
#include <QPainter>
#include <cmath>
#include <qnamespace.h>


Paintt::Paintt(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Paintt::~Paintt()
{

}

// Реализуем метод отрисовки
void Paintt::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red); 
    for(auto p: points) {
        painter->drawEllipse(p.x() - 5, p.y() - 5, 10, 10);
    }

    painter->setBrush(Qt::NoBrush);
    
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
