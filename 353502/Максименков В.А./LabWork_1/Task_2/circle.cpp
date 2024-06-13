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

void Circle::resizeShape(QPointF now)
{
    qreal distance = sqrt((now.x() - centerOfShape.x()) * (now.x() - centerOfShape.x()) + (now.y() - centerOfShape.y()) * (now.y() - centerOfShape.y()));
    radius += distance - defaultDistance;
    update();
    emit updateShape();
    defaultDistance = distance;
}

qreal Circle::squareOfShape()
{
    return 3.1416 * radius * radius;
}

qreal Circle::perimetrOfShape()
{
    return 2 * 3.1416 * radius;
}

Circle::Circle()
{
    setPos(100, 100);
    centerOfShape = QPointF(100, 100);
}
