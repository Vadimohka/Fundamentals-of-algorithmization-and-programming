#include "rectangle.h"


QRectF Rectangle::boundingRect() const
{
    return QRectF(-halfSide1, -halfSide2, 2*halfSide1, 2*halfSide2);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawRect(-halfSide1, -halfSide2, 2*halfSide1, 2*halfSide2);
}

void Rectangle::resizeShape(QPointF now)
{
    qreal distance = sqrt((now.x() - centerOfShape.x()) * (now.x() - centerOfShape.x()) + (now.y() - centerOfShape.y()) * (now.y() - centerOfShape.y()));
    qreal diagonal = sqrt(halfSide1*halfSide1 + halfSide2*halfSide2);
    halfSide1 = ((diagonal + distance - defaultDistance)*halfSide1)/diagonal;
    halfSide2 = ((diagonal + distance - defaultDistance)*halfSide2)/diagonal;
    update();
    emit updateShape();
    defaultDistance = distance;
}

qreal Rectangle::squareOfShape()
{
    return halfSide1 * halfSide2 * 4;
}

qreal Rectangle::perimetrOfShape()
{
    return (halfSide1 + halfSide2) * 4;
}

void Rectangle::reinterpret(qreal parametr1, qreal parametr2)
{
    halfSide1 = parametr1 / 2;
    halfSide2 = parametr2 / 2;
    update();
    emit updateShape();
}

Rectangle::Rectangle()
{
    setPos(200, 100);
    centerOfShape = QPointF(200, 100);
}
