#ifndef STARSIX_H
#define STARSIX_H

#include "shape.h"

class Star6: public Shape
{
public:
    Star6();

private:
    float radius1 = 80;
    float radius2 = 80;
    int count = 6;
    float area() override;
    float perimeter() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // STARSIX_H

