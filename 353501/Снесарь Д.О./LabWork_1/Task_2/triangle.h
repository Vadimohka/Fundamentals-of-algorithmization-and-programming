#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape
{
public:
    Triangle(QPointF first, QPointF second);
    void setSize(QPointF nPoint) override;
};

#endif // TRIANGLE_H
