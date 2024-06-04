#ifndef TTYPEFIGURE_H
#define TTYPEFIGURE_H

#include "figureitem.h"

class TtypeFigure : public FigureItem
{
public:    
    TtypeFigure(qreal qUnit, GameField* field, QPointF pos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TypesOfFigures::type getTypeOfFigure() override;

    QPainterPath shape() const override;
};

#endif // TTYPEFIGURE_H
