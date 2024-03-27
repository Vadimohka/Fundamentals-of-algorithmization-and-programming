#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"

class Triangle:public Shape
{
public:
    Triangle();
    Triangle(double a,double b,double c);
    ~Triangle();
    double a;
    double b;
    double c;
    double xA;
    double yA;
public slots:
    void updateSideA(double a);
    void updateSideB(double b);
    void updateSideC(double c);
    void updateVertices(double a,double b,double c);
private:
    void paint(QPainter*p);

};

#endif // TRIANGLE_H
