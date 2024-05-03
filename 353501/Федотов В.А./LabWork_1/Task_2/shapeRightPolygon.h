#ifndef SHAPERIGHTPOLYGON_H
#define SHAPERIGHTPOLYGON_H

#include "shape.h"

class ShapeRightPolygon : public Shape
{
public:
    ShapeRightPolygon();

    // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:

    void calculatePoints() override;

    void clear() override;
};

#endif // SHAPERIGHTPOLYGON_H
