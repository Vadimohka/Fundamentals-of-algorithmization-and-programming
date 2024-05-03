#ifndef LEFTHANDMAN_H
#define LEFTHANDMAN_H


#include "movingrectangle.h"

class LeftHandMan: public MovingRectangle
{
    Q_OBJECT
public:
    LeftHandMan();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // LEFTHANDMAN_H
