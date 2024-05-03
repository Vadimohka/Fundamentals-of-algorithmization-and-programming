#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "shape.h"

class Rhombus : public Shape
{
public:
    Rhombus(QPointF first, QPointF second);
    void setSize(QPointF nPoint) override;
};

#endif // RHOMBUS_H
