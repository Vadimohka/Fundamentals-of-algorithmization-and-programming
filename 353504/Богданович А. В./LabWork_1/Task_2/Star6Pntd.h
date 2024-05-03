#ifndef STAR6PNTD_H
#define STAR6PNTD_H

#include "Figure.h"

class Star6Pntd : public Figure
{
public:
    Star6Pntd();
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

#endif // STAR6PNTD_H
