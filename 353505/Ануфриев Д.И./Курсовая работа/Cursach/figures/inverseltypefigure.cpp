#include "inverseltypefigure.h"

InverseLTypeFigure::InverseLTypeFigure(qreal qUnit, GameField* field, QPointF pos) : FigureItem(field, pos)
{
    this->setTransformOriginPoint(1.5 * qUnit, 1.5 * qUnit);
    this->setScale(0.9);

    this->field = field;
    this->qUnit = qUnit;
}

QRectF InverseLTypeFigure::boundingRect() const
{
    return QRectF(0, 0, 3 * qUnit, 3 * qUnit);
}

void InverseLTypeFigure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor("#4395FF"));
    painter->setPen(QPen(QColor("#0E77FF"), 3));


    painter->drawRect(qUnit, 0, qUnit, qUnit);
    painter->drawRect(qUnit, qUnit, qUnit, qUnit);
    painter->drawRect(qUnit, 2 * qUnit, qUnit, qUnit);
    painter->drawRect(0, 2 * qUnit, qUnit, qUnit);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

TypesOfFigures::type InverseLTypeFigure::getTypeOfFigure()
{
    return TypesOfFigures::type::LType;
}

QPainterPath InverseLTypeFigure::shape() const
{
    QPainterPath path;
    path.addRect(qUnit, 0, qUnit, qUnit);
    path.addRect(qUnit, qUnit, qUnit, qUnit);
    path.addRect(qUnit, 2 * qUnit, qUnit, qUnit);
    path.addRect(0, 2 * qUnit, qUnit, qUnit);

    return path;
}
