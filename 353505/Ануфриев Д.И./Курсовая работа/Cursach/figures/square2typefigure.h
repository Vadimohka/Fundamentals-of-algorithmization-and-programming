#ifndef SQUARE2TYPEFIGURE_H
#define SQUARE2TYPEFIGURE_H

#include "figureitem.h"

class Square2TypeFigure : public FigureItem
{
    Q_OBJECT

public:

    Square2TypeFigure(qreal qUnit, GameField* field, QPointF pos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TypesOfFigures::type getTypeOfFigure() override;

    QPainterPath shape() const override;

private:
};

#endif // SQUARE2TYPEFIGURE_H
