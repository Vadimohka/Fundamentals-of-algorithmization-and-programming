#ifndef RIGHT_POLYGONE_H
#define RIGHT_POLYGONE_H
#include "shape.h"
class Right_Polygone : public Shape
{
    int side = 50;
    int apexes_num = 4;
public:
    Right_Polygone();
    qreal calculateArea() override;
    qreal calculatePerimeter() override;
    void number_apexes(int number) override;
    void changeSide(double spinside);
    void calculatePoints() override;
};

#endif // RIGHT_POLYGONE_H
