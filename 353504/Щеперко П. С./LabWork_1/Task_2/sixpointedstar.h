#ifndef SIXPOINTEDSTAR_H
#define SIXPOINTEDSTAR_H

#include "figure.h"

class SixPointedStar : public Figure
{
public:
    SixPointedStar();
    float r1 = 0;
    float r2 = 0;
    int points = 6;
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

#endif // SIXPOINTEDSTAR
