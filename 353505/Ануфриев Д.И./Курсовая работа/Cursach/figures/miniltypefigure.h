#ifndef MINILTYPEFIGURE_H
#define MINILTYPEFIGURE_H

#include <figureitem.h>

class MiniLTypeFigure : public FigureItem
{
public:
    MiniLTypeFigure(qreal qUnit, GameField* field, QPointF pos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    TypesOfFigures::type getTypeOfFigure() override;

    QPainterPath shape() const override;

private:
    qreal qUnit = 0;

};

#endif // MINILTYPEFIGURE_H
