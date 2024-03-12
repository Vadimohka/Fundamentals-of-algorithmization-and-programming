#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "basicshape.h"

class Rectangle : public BasicShape
{
public:
    Rectangle();
    float area() override;
    float perimeter() override;
    void setLength(int value) override;
    void setWidth(int value) override;
    float getLength() override;
    float getWidth() override;
private:
    int length = 100;
    int width = 50;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
        };

#endif // RECTANGLE_H
