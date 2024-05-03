#ifndef STAR_H
#define STAR_H
#include "shape.h"
class Star : public Shape
{
public:
    Star();
    void numberApexes(int apexes) override;
    
    int apexes_num = 6;
    qreal area() override;
    qreal perimeter() override;
    void calculate_points();
    void changeRadius1(double spinrad1) override;
    void changeRadius2(double spinrad2) override;
};

#endif // STAR_H
