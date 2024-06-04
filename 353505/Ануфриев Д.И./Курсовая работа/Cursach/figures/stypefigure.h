#ifndef STYPEFIGURE_H
#define STYPEFIGURE_H

#include <figureitem.h>

class STypeFigure : public FigureItem
{
public:
    STypeFigure(qreal qUnit, GameField* field, QPointF pos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TypesOfFigures::type getTypeOfFigure() override;

    QPainterPath shape() const override;

private:
    qreal qUnit = 0;
};

#endif // STYPEFIGURE_H
