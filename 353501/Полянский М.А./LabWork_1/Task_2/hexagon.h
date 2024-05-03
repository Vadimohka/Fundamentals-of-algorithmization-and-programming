#ifndef RIGHT_POLYGONE_H
#define RIGHT_POLYGONE_H
#include "shape.h"
class Hexagon : public Shape
{
    
public:
    Hexagon();
    void numberApexes(int number) override;
    qreal area() override;
    qreal perimeter() override;
    void change_side(double spinside) override;
    void calculate_points();
};

#endif // RIGHT_POLYGONE_H
