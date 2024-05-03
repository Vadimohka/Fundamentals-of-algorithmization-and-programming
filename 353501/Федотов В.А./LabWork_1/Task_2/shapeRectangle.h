#ifndef SHAPERECTANGLE_H
#define SHAPERECTANGLE_H

#include "shape.h"

class ShapeRectangle : public Shape
{
public:
    ShapeRectangle();

    // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    void calculatePoints() override;

    void clear() override;
};

#endif // SHAPERECTANGLE_H
