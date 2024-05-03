#ifndef ROMB_H
#define ROMB_H

#include "shape.h"

class Romb : public Shape
{
public:
    explicit Romb(QPointF point);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    qreal GetSquare();
    qreal GetPerimetr();
    QPointF GetCenter();

};

#endif // ROMB_H
