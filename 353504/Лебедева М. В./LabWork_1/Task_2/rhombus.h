#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figures.h"

class Rhombus: public Figures
{
public:
    float size = 45;
    Rhombus();
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RHOMBUS_H
