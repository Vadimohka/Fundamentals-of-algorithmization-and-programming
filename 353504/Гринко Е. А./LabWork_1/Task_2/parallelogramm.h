#ifndef PARALLELOGRAMM_H
#define PARALLELOGRAMM_H
#include "shape.h"

class Parallelogramm:public Shape
{
public:
    Parallelogramm();
    Parallelogramm(double a, double b, double angle);
    ~Parallelogramm();
    double a;
    double b;
    double angle;
    double radian;

    void updateParall(double a,double b,double angle);
    void updateSideA(double a);
    void updateSideB(double b);

private:
    void paint(QPainter*p);
};

#endif // PARALLELOGRAMM_H
