#include "romb.h"

QRectF Romb::boundingRect() const
{
    return QRectF(-halfDiagonal2, -halfDiagonal2, 2*halfDiagonal2, 2*halfDiagonal2);
}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPointF A = QPointF(-halfDiagonal1, 0.0);
    QPointF B = QPointF(0.0, -halfDiagonal2);
    QPointF C = QPointF(halfDiagonal1, 0.0);
    QPointF D = QPointF(0.0, halfDiagonal2);

    painter->rotate(angle);

    painter->drawLine(A, B);
    painter->drawLine(B, C);
    painter->drawLine(C, D);
    painter->drawLine(D, A);
}


qreal Romb::squareOfFigure()
{
    return halfDiagonal1 * halfDiagonal2 * 2;
}

qreal Romb::perimetrOfFigure()
{
    qreal side = sqrt(halfDiagonal1*halfDiagonal1 + halfDiagonal2*halfDiagonal2);
    return side * 4;
}

void Romb::resize(qreal changeSize)
{
    halfDiagonal1 *= changeSize;
    halfDiagonal2 *= changeSize;
    update();
    emit updateFigure();
}

Romb::Romb()
{
    setPos(300, 100);
    centerOfFigure = QPointF(200, 100);
}
