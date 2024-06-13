#include "rectangle.h"

#include <QPainter>

Rectangle::Rectangle(QPointF point, QObject *parent) :
    Figure(point,parent) {}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 2));
    painter->drawRect(QRectF(startPoint(), endPoint()));

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
