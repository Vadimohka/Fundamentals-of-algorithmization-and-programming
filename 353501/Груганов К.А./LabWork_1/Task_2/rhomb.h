#ifndef RHOMB_H
#define RHOMB_H
#include"shape.h"

class Rhomb:public Shape
{
public:
    Rhomb();
    Rhomb(double h1,double h2);
    ~Rhomb();
    double h1;
    double h2;

    void updateRhomb(double h1,double h2);
    void updateH1(double h1);
    void updateH2(double h2);
private:
    void paint(QPainter*p);
};

#endif // RHOMB_H
