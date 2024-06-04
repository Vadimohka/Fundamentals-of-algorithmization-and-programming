#ifndef CIRCLE_H
#define CIRCLE_H
#include"shape.h"

class Circle:public Shape
{
public:
    Circle();
    Circle(double R);
    ~Circle();
    double R;

    void updateCircle(double R);
private:
    void paint(QPainter*p);
};

#endif // CIRCLE_H
