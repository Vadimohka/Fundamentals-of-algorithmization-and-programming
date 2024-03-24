#ifndef SHAPESQUARE_H
#define SHAPESQUARE_H

#include "shape.h"

class ShapeSquare : public Shape
{
public:
    ShapeSquare();

    // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:

    void calculatePoints() override;
    void clear() override;

};

#endif // SHAPESQUARE_H
