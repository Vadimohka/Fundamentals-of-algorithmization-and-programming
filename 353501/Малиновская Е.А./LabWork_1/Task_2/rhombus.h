#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "shape.h"
class Rhombus : public Shape
{
    double side = 100;
    double angle = 60;
public:
    qreal calculateArea() override;
    qreal calculatePerimeter() override;
    void changeSide(double spinside);
    void changeAngle(double spinangle);
    void calculatePoints() override;
    Rhombus();
};

#endif // RHOMBUS_H
