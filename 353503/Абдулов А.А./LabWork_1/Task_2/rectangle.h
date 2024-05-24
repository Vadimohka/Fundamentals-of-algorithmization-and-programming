#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"figure.h"


class rectangle: public Figure{
public:
    rectangle();
    float length=125;
    float width=75;
    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RECTANGLE_H
