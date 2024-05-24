#ifndef BIGLTYPEFIGURE_H
#define BIGLTYPEFIGURE_H

#include "figureitem.h"
class BigLTypeFigure: public FigureItem
{
public:
    BigLTypeFigure(qreal qUnit, GameField* field, QPointF pos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TypesOfFigures::type getTypeOfFigure() override;

    QPainterPath shape() const override;

private:
    qreal qUnit = 0;

};

#endif // BIGLTYPEFIGURE_H
