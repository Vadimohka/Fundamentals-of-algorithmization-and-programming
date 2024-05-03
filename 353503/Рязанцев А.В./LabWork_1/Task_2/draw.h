#ifndef DRAW_H
#define DRAW_H

#include "shape.h"

class Draw : public Shape
{
public:
    Draw(QPointF);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    qreal GetSquare();
    qreal GetPerimetr();
    QPointF GetCenter();
};

#endif // DRAW_H
