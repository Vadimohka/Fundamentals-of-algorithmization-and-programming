#ifndef SHAPESTAR_H
#define SHAPESTAR_H

#include "shape.h"

class ShapeStar : public Shape
{
public:
    ShapeStar();

    // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:

    void calculatePoints() override;

    void clear() override;
};

#endif // SHAPESTAR_H
