#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "shape.h"

class Rhombus : public Shape
{
    
public:
    qreal area() override;
    qreal perimeter() override;
    void change_side(double spinside) override;
    void changeangle(double spinangle) override;
    void calculate_points();
    Rhombus();
};

#endif // RHOMBUS_H
