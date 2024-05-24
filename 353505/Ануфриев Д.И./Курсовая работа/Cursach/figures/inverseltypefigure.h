#ifndef INVERSELTYPEFIGURE_H
#define INVERSELTYPEFIGURE_H

#include <figureitem.h>

class InverseLTypeFigure : public FigureItem
{
public:
    InverseLTypeFigure(qreal qUnit, GameField* field, QPointF pos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TypesOfFigures::type getTypeOfFigure() override;

    QPainterPath shape() const override;

private:
    qreal qUnit = 0;

};

#endif // INVERSELTYPEFIGURE_H
