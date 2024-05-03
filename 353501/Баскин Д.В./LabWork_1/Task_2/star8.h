#ifndef STAR8_H
#define STAR8_H

#include "basicshape.h"

class Star8: public BasicShape
{
public:
    Star8();
    float area() override;
    float perimeter() override;
    void setRadiusA(int value) override;
    void setRadiusB(int value) override;
    float getRadiusA() override;
    float getRadiusB() override;
private:
    float radiusA = 100;
    float radiusB = 50;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};


#endif // STAR8_H
