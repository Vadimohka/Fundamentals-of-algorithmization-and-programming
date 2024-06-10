#include "rectangle.h"


QRectF Rectangle::boundingRect() const
{
    qreal a = sqrt(halfSide1 * halfSide1 + halfSide2 * halfSide2);
    return QRectF(-a, -a, 2*a, 2*a);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->rotate(angle);
    painter->drawRect(-halfSide1, -halfSide2, 2*halfSide1, 2*halfSide2);
}


qreal Rectangle::squareOfFigure()
{
    return halfSide1 * halfSide2 * 4;
}

qreal Rectangle::perimetrOfFigure()
{
    return (halfSide1 + halfSide2) * 4;
}

void Rectangle::resize(qreal changeSize)
{
    halfSide1 *= changeSize;
    halfSide2 *= changeSize;
    update();
    emit updateFigure();
}

Rectangle::Rectangle()
{
    setPos(200, 100);
    centerOfFigure = QPointF(200, 100);
}
