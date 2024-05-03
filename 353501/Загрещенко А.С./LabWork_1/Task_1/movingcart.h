#ifndef MOVINGCART_H
#define MOVINGCART_H

#include "movingrect.h"

class MovingCart : public MovingRect
{
public:
    MovingCart();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
protected:
    double angle_wheel;
};

#endif // MOVINGCART_H
