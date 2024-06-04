#ifndef SQUARE_H
#define SQUARE_H

#include"figure.h"

class Square: public Figure{

public:
    Square();
    float size=100;
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // SQUARE_H
