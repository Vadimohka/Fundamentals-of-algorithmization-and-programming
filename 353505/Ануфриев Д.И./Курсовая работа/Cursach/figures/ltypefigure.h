#ifndef LTYPEFIGURE_H
#define LTYPEFIGURE_H

#include <figureitem.h>

class LtypeFigure : public FigureItem
{
public:
    LtypeFigure(qreal qUnit, GameField* field, QPointF pos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TypesOfFigures::type getTypeOfFigure() override;

    QPainterPath shape() const override;

private:
    qreal qUnit = 0;

};

#endif // LTYPEFIGURE_H
