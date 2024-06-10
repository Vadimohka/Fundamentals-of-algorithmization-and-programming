#include "circle.h"

QRectF Circle::boundingRect() const
{
    return QRectF(-radius, -radius, 2*radius, 2*radius);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawEllipse(center, radius, radius);
}
qreal Circle::squareOfFigure()
{
    return 3.1416 * radius * radius;
}

qreal Circle::perimetrOfFigure()
{
    return 2 * 3.1416 * radius;
}

void Circle::resize(qreal changeSize)
{
    radius*=changeSize;
    update();
}

Circle::Circle()
{
    setPos(100, 100);
    centerOfFigure = QPointF(100, 100);
}
