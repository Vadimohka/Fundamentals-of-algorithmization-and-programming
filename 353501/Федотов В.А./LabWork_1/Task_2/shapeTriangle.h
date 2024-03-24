#ifndef SHAPETRIANGLE_H
#define SHAPETRIANGLE_H

#include "shape.h"

class ShapeTriangle : public Shape
{
public:
    ShapeTriangle();

    // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:

    void calculatePoints() override;

    void clear() override;


};

#endif // SHAPETRIANGLE_H
