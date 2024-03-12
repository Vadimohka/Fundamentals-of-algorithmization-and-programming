#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"shape.h"


class rectangle: public Shape
{
public:
    rectangle();


    double lenin = 2;
    double stalin = 2;

    float area() override;
    float perimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    void updateSizeStorona( double arg1) override;
    void updateSizeStoronaW( double arg1) override;
};

#endif // RECTANGLE_H
