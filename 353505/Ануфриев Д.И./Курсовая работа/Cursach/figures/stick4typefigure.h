#ifndef STICK4TYPEFIGURE_H
#define STICK4TYPEFIGURE_H

#include "figureitem.h"

class Stick4TypeFigure : public FigureItem
{
public:
    Stick4TypeFigure(qreal qUnit, GameField* field, QPointF pos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TypesOfFigures::type getTypeOfFigure() override;

    QPainterPath shape() const override;
};

#endif // STICK4TYPEFIGURE_H
