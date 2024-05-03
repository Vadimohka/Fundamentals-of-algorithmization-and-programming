#ifndef SQUARE_H
#define SQUARE_H

#include"shape.h"

class Square: public Shape
{
public:
    Square();
    float size=150;
    float area() override;
    float perimeter() override;
private:
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // SQUARE_H
