#include "figures/diagonalstick2figure.h"

DiagonalStick2Figure::DiagonalStick2Figure(qreal qUnit, GameField* field, QPointF pos) : FigureItem(field, pos)
{
    this->setTransformOriginPoint(1.5 * qUnit, 1.5 * qUnit);
    this->setScale(0.9);

    this->field = field;
    this->qUnit = qUnit;
}

QRectF DiagonalStick2Figure::boundingRect() const
{
    return QRectF(0, 0, 3 * qUnit, 3 * qUnit);
}

void DiagonalStick2Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor("#4395FF"));
    painter->setPen(QPen(QColor("#0E77FF"), 3));


    painter->drawRect(0, 0, qUnit, qUnit);
    painter->drawRect(qUnit, qUnit, qUnit, qUnit);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

TypesOfFigures::type DiagonalStick2Figure::getTypeOfFigure()
{
    return TypesOfFigures::type::DiagonalStick2Type;
}

QPainterPath DiagonalStick2Figure::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, qUnit, qUnit);
    path.addRect(qUnit, qUnit, qUnit, qUnit);


    return path;
}
