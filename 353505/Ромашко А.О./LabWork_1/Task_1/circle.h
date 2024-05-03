#ifndef CIRCLE_H
#define CIRCLE_H

#include <QWidget>
#include <QGraphicsEllipseItem>
#include "rectangle.h"

class Circle : public QGraphicsEllipseItem
{
public:
    Circle();
    QGraphicsEllipseItem *circle;
public:
   virtual void advance(int phase);
   int xspeed = 2;
};

#endif // CIRCLE_H
