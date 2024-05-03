#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "rectangle.h"

class Parallelogram: public Rectangle
{
public:
    Parallelogram();
    float area() override;
    void setLength(int value) override;
    void setWidth(int value) override;
    void setAngle(int value) override;
    float getLength() override;
    float getWidth() override;
    float getAngle() override;
private:
    int length = 100;
    int width = 80;
    int angle = 45;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // PARALLELOGRAM_H
