#include "ellipse.h"

Ellipse::Ellipse(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):QGraphicsEllipseItem(x, y, width, height, parent)
{
    setBrush(Qt::yellow);
}
