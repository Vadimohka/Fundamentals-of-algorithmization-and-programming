#ifndef DIAGONALSTICK2FIGURE_H
#define DIAGONALSTICK2FIGURE_H

#include "figureitem.h"
class DiagonalStick2Figure: public FigureItem
{
public:
    DiagonalStick2Figure(qreal qUnit, GameField* field, QPointF pos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TypesOfFigures::type getTypeOfFigure() override;

    QPainterPath shape() const override;

private:
    qreal qUnit = 0;

};


#endif // DIAGONALSTICK2FIGURE_H
