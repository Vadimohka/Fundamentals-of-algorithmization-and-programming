#ifndef HEXAGON_H
#define HEXAGON_H

#include "shape.h"

class Hexagon : public Shape
{
public:
    Hexagon(QPointF first, QPointF second);
    void setSize(QPointF nPoint) override;
};

#endif // HEXAGON_H
