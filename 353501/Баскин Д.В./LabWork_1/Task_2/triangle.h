#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "basicshape.h"

class Triangle : public BasicShape
{
public:
    Triangle();
    float area() override;
    float perimeter() override;
    void setLength(int value) override;
    void setWidth(int value) override;
    void setAngle(int value) override;
    float getLength() override;
    float getWidth() override;
    float getAngle() override;
private:
    int length = 100;
    int width = 100;
    int angle = 60;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // TRIANGLE_H
