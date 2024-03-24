#ifndef SHAPECIRCLE_H
#define SHAPECIRCLE_H

#include "shape.h"

class ShapeCircle : public Shape
{
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:

    qreal area() override;
    qreal perimeter() override;

    void clear() override;
};

#endif // SHAPECIRCLE_H
