#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"shape.h"

class Rectangle:public Shape
{
public:
    Rectangle();
    Rectangle(double a,double b);
    ~Rectangle();
    double a;
    double b;

    void updateRect(double a,double b);
    void updateWidth(double width);
    void updateHeight(double height);

private:
    void paint(QPainter*p);
};

#endif // RECTANGLE_H
