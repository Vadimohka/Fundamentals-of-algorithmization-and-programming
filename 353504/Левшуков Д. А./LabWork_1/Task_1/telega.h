#ifndef TELEGA_H
#define TELEGA_H

#include "rectangle.h"

class telega : public rectangle
{
public:
    telega();
    void draw(QPainter *p);
    void drive(int n);
protected:
    qreal r=60,spice_angle=0;
    void drawWheels(QPainter *p);
    void drawRoad(QPainter *p);
    void update_spices();
    QPair<QPointF,QPointF> l1,l2;
    QPointF c1,c2;
};

#endif // TELEGA_H
