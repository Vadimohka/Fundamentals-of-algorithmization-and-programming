#ifndef STAR6_H
#define STAR6_H

#include "basicshape.h"

class Star6: public BasicShape
{
public:
    Star6();
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


#endif // STAR6_H
