#ifndef INVERSESTYPEFIGURE_H
#define INVERSESTYPEFIGURE_H

#include "figureitem.h"

class InverseSTypeFigure : public FigureItem
{
public:
    InverseSTypeFigure(qreal qUnit, GameField* field, QPointF pos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TypesOfFigures::type getTypeOfFigure() override;

    QPainterPath shape() const override;

private:
    qreal qUnit = 0;
};

#endif // INVERSESTYPEFIGURE_H
