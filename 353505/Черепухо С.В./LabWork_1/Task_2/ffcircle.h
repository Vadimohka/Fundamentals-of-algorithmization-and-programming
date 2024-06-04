#ifndef FFCIRCLE_H
#define FFCIRCLE_H

#define PI 3.1415926535898

#include "figure.h"

class ffCircle : public figure
{
public:
    ffCircle();

    float radius;

    virtual void findPerimetr();
    virtual void findArea();

    virtual void setPoints(QPoint msBeg, QPoint msNow);
    virtual void draw(QPainter *painter);
    virtual void scalingPoint(int ch);
};

#endif // FFCIRCLE_H
