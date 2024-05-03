#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"


class Rectangle : public Shape
{
public:
    explicit Rectangle(QPointF point);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    qreal GetSquare();
    qreal GetPerimetr();
    QPointF GetCenter();

};

#endif // RECTANGLE_H
