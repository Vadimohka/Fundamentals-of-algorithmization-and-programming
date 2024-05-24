#include "square2typefigure.h"

Square2TypeFigure::Square2TypeFigure(qreal qUnit, GameField* field, QPointF pos) : FigureItem(field, pos)
{
    this->setTransformOriginPoint(1.5 * qUnit, 1.5 * qUnit);
    this->setScale(0.9);

    this->field = field;
    this->qUnit = qUnit;
}

QRectF Square2TypeFigure::boundingRect() const
{
    return QRectF(0, 0, 3 * qUnit, 3 * qUnit);
}

void Square2TypeFigure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor("#4395FF"));
    painter->setPen(QPen(QColor("#0E77FF"), 3));


    painter->drawRect(0, 0, qUnit, qUnit);
    painter->drawRect(0, 1 * qUnit, qUnit, qUnit);
    painter->drawRect(qUnit, 0, qUnit, qUnit);
    painter->drawRect(qUnit, 1*  qUnit, qUnit, qUnit);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

TypesOfFigures::type Square2TypeFigure::getTypeOfFigure()
{
    return TypesOfFigures::type::Square2Type;
}

QPainterPath Square2TypeFigure::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, qUnit, qUnit);
    path.addRect(0, 1 * qUnit, qUnit, qUnit);
    path.addRect(qUnit, 0, qUnit, qUnit);
    path.addRect(qUnit, 1*  qUnit, qUnit, qUnit);

    return path;
}
