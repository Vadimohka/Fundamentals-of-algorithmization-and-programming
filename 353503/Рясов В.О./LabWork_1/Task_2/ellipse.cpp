#include "ellipse.h"

#include <QPainter>
Ellipse::Ellipse(QPointF point, QObject *parent) :
    Figure(point,parent) {}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 2));
    painter->drawEllipse(QRectF(startPoint(), endPoint()));

    Q_UNUSED(widget)
    Q_UNUSED(option)
}
