#ifndef STAR_H
#define STAR_H
#include "shape.h"
class Star : public Shape
{
public:
    Star();
    void number_apexes(int number) override;
    double radius1 = 40;
    double radius2 = 80;
    int apexes_num = 5;
    qreal calculateArea() override;
    qreal calculatePerimeter() override;
    void calculatePoints() override;
    void change_radius1(double spinrad1);
    void change_radius2(double spinrad2);
};

#endif // STAR_H
