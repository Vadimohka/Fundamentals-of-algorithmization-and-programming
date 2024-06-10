#include "square.h"

QRectF Square::boundingRect() const
{
    qreal a = sqrt(halfSide * halfSide + halfSide * halfSide);
    return QRectF(-a, -a, 2*a, 2*a);
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->rotate(angle);
    painter->drawRect(-halfSide, -halfSide, 2*halfSide, 2*halfSide);
}

void Square::resize(qreal changeSize)
{
    halfSide *= changeSize;
    update();
}

qreal Square::squareOfFigure()
{
    return halfSide * halfSide * 4;
}

qreal Square::perimetrOfFigure()
{
    return halfSide * 8;
}

Square::Square()
{
    setPos(100, 300);
    centerOfFigure = QPointF(100, 300);
}
