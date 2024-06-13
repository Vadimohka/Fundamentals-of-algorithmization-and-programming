#include "virtualshape.h"

VirtualShape::VirtualShape() {}

void VirtualShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF VirtualShape::boundingRect() const
{
    return QRectF(-1000, -1000, 2000, 2000);
}

void VirtualShape::resizeShape(QPointF now)
{
    Q_UNUSED(now);
}

qreal VirtualShape::squareOfShape()
{
    return 0.0;
}

qreal VirtualShape::perimetrOfShape()
{
    return 0.0;
}
