#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class Ellipse : public Shape
{
public:
    Ellipse(QPointF);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    qreal GetSquare();
    qreal GetPerimetr();
    QPointF GetCenter();
};

#endif // ELLIPSE_H
