#ifndef CART_H
#define CART_H

#include "movingrectangle.h"

class Cart : public MovingRectangle
{
    Q_OBJECT

public:
    Cart(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;
};

#endif // CART_H
