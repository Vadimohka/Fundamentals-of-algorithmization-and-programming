#ifndef HEXAGON_H
#define HEXAGON_H

#include "shape.h"

class Hexagon : public Shape
{
public:
    explicit Hexagon(QPointF point);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    qreal GetSquare();
    qreal GetPerimetr();
    QPointF GetCenter();
};

#endif // HEXAGON_H
