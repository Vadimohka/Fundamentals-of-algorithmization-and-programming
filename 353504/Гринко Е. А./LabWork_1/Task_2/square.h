#ifndef SQUARE_H
#define SQUARE_H
#include"shape.h"

class Square:public Shape
{
public:
    Square();
    Square(double a);
    ~Square();

    void updateSquare(double a);
    double a;

private:
    void paint(QPainter*p);
};

#endif // SQUARE_H
