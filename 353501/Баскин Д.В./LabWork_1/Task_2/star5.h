#ifndef STAR5_H
#define STAR5_H

#include "basicshape.h"

class Star5: public BasicShape
{
public:
    Star5();
    float area() override;
    float perimeter() override;
    void setRadiusA(int value) override;
    void setRadiusB(int value) override;
    float getRadiusA() override;
    float getRadiusB() override;
private:
    int radiusA = 100;
    int radiusB = 50;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};


#endif // STAR5_H
