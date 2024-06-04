#include "stick4typefigure.h".h"

Stick4TypeFigure::Stick4TypeFigure(qreal qUnit, GameField* field, QPointF pos) : FigureItem(field, pos)
{
    this->setTransformOriginPoint(2 * qUnit, 2 * qUnit);
    this->setScale(0.9);

    this->field = field;
    this->qUnit = qUnit;
}

QRectF Stick4TypeFigure::boundingRect() const
{
    return QRectF(0, 0, 4 * qUnit, 4 * qUnit);
}

void Stick4TypeFigure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor("#4395FF"));
    painter->setPen(QPen(QColor("#0E77FF"), 3));


    painter->drawRect(qUnit, 0, qUnit, qUnit);
    painter->drawRect(qUnit, 1 * qUnit, qUnit, qUnit);
    painter->drawRect(qUnit, 2 * qUnit, qUnit, qUnit);
    painter->drawRect(qUnit, 3 * qUnit, qUnit, qUnit);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

TypesOfFigures::type Stick4TypeFigure::getTypeOfFigure()
{
    return TypesOfFigures::type::Stick4Type;
}

QPainterPath Stick4TypeFigure::shape() const
{
    QPainterPath path;
    path.addRect(qUnit, 0, qUnit, qUnit);
    path.addRect(qUnit, 1 * qUnit, qUnit, qUnit);
    path.addRect(qUnit, 2 * qUnit, qUnit, qUnit);
    path.addRect(qUnit, 3 * qUnit, qUnit, qUnit);

    return path;
}
