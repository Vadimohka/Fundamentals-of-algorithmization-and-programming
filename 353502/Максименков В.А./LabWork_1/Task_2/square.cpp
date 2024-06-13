#include "square.h"

QRectF Square::boundingRect() const
{
    return QRectF(-halfSide, -halfSide, 2*halfSide, 2*halfSide);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawRect(-halfSide, -halfSide, 2*halfSide, 2*halfSide);
}

void Square::resizeShape(QPointF now)
{
    qreal distance = sqrt((now.x() - centerOfShape.x()) * (now.x() - centerOfShape.x()) + (now.y() - centerOfShape.y()) * (now.y() - centerOfShape.y()));
    halfSide += distance - defaultDistance;
    update();
    emit updateShape();
    defaultDistance = distance;
}

qreal Square::squareOfShape()
{
    return halfSide * halfSide * 4;
}

qreal Square::perimetrOfShape()
{
    return halfSide * 8;
}

Square::Square()
{
    setPos(100, 300);
    centerOfShape = QPointF(100, 300);
}
