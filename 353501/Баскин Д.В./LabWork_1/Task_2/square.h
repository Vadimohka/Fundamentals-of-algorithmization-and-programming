#ifndef SQUARE_H
#define SQUARE_H

#include "basicshape.h"

class Square : public BasicShape
{
public:
    Square();
    float area() override;
    float perimeter() override;
    void setSide(int value) override;
    float getSide() override;
private:
    int side = 100;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // SQUARE_H
