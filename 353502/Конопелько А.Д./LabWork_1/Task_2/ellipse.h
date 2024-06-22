#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "moveitem.h"

class Ellipse : public MoveItem
{
public:
    Ellipse();
    qreal findPerimeter();
    qreal findSquare();
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Ellipse();
};

#endif // ELLIPSE_H
