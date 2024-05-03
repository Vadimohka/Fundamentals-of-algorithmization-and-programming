#ifndef STAR5PNTD_H
#define STAR5PNTD_H

#include "Figure.h"

class Star5Pntd : public Figure
{
public:
    Star5Pntd();
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

#endif // STAR5PNTD_H

