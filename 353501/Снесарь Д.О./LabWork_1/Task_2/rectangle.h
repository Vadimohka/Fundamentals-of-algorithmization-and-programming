#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(QPointF first, QPointF second);
    void setSize(QPointF nPoint) override;
};

#endif // RECTANGLE_H
