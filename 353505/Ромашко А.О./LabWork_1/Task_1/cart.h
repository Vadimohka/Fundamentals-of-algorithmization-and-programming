#ifndef CART_H
#define CART_H

#include "rectangle.h"
#include "circle.h"
#include <QTimer>

class Cart: public Rectangle
{
public://values
    Cart();
    Rectangle *rect;
    Circle *circle1;
    Circle *circle2;
    QGraphicsItemGroup *group;
    QTimer *animationTimer;

public://functions
    QGraphicsItemGroup *returnCartGroup(QGraphicsItemGroup *group);
    void speed(int speedVal);
    void stop();
public slots:
     void advance(int phase);
};

#endif // CART_H
