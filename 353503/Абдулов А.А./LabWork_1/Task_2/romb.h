#ifndef ROMB_H
#define ROMB_H

#include "figure.h"

class Romb: public Figure{
public:
    float size = 100;
    Romb();
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // ROMB_H
