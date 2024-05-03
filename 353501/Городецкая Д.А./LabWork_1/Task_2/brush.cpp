#include "brush.h"
#include <QPainter>
#include <cmath>
#include <qnamespace.h>


Brush::Brush(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Brush::~Brush()
{

}

// Реализуем метод отрисовки
void Brush::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white); 
    for(auto p: points) {
        painter->drawEllipse(p.x() - 5, p.y() - 5, 10, 10);
    }

    painter->setBrush(Qt::NoBrush);
    
    Q_UNUSED(option)
    Q_UNUSED(widget)
}