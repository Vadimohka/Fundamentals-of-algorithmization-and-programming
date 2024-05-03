#ifndef CIRCLE_H
#define CIRCLE_H

#include "base.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

class circle: public base
{
public:
    //circle();
    void draw(QGraphicsScene *scene, int width, int height, int a, int &h)override;
    void getParametrs(int &side1, int &side2, int &side3, int a) override;
    void perSquareMasse(int width, int height, int a)override;
};

#endif // CIRCLE_H
