#include "romb.h"

QRectF Romb::boundingRect() const
{
    return QRectF(-halfDiagonal1, -halfDiagonal2, 2*halfDiagonal1, 2*halfDiagonal2);
}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPointF A = QPointF(-halfDiagonal1, 0.0);
    QPointF B = QPointF(0.0, -halfDiagonal2);
    QPointF C = QPointF(halfDiagonal1, 0.0);
    QPointF D = QPointF(0.0, halfDiagonal2);

    painter->drawLine(A, B);
    painter->drawLine(B, C);
    painter->drawLine(C, D);
    painter->drawLine(D, A);
}

void Romb::resizeShape(QPointF now)
{
    qreal distance = sqrt((now.x() - centerOfShape.x()) * (now.x() - centerOfShape.x()) + (now.y() - centerOfShape.y()) * (now.y() - centerOfShape.y()));
    qreal side = sqrt(halfDiagonal1*halfDiagonal1 + halfDiagonal2*halfDiagonal2);
    halfDiagonal1 = ((side + distance - defaultDistance)*halfDiagonal1)/side;
    halfDiagonal2 = ((side + distance - defaultDistance)*halfDiagonal2)/side;
    update();
    emit updateShape();
    defaultDistance = distance;
}

qreal Romb::squareOfShape()
{
    return halfDiagonal1 * halfDiagonal2 * 2;
}

qreal Romb::perimetrOfShape()
{
    qreal side = sqrt(halfDiagonal1*halfDiagonal1 + halfDiagonal2*halfDiagonal2);
    return side * 4;
}

void Romb::reinterpret(qreal parametr1, qreal parametr2)
{
    halfDiagonal1 = parametr1 / 2;
    halfDiagonal2 = parametr2 / 2;
    update();
    emit updateShape();
}

Romb::Romb()
{
    setPos(300, 100);
    centerOfShape = QPointF(200, 100);
}
