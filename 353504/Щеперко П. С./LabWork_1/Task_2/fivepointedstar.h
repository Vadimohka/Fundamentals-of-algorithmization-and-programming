#ifndef FIVEPOINTEDSTAR_H
#define FIVEPOINTEDSTAR_H

#include "figure.h"

class FivePointedStar : public Figure
{
public:
    FivePointedStar();
    float r1 = 0;
    float r2 = 0;
    int points = 5;
    float findArea() override;
    float findPerimeter() override;
    void setRs(float, float);
    float getR1();
    float getR2();
    void setPoints(int);
    int getPoints();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // FIVEPOINTEDSTAR_H

