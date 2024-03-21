#ifndef STAR8PNTD_H
#define STAR8PNTD_H

#include "Figure.h"

class Star8Pntd : public Figure
{
public:
    Star8Pntd();
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

#endif // STAR8PNTD_H
