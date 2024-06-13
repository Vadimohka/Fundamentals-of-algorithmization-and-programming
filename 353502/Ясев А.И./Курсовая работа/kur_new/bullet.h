#ifndef BULLET_H
#define BULLET_H

#include "square.h"

class Bullet : public Square
{

public:
    Bullet(qreal x0, qreal y0, Direction direction, bool isDD, QGraphicsObject *parent = 0);
    ~Bullet();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Direction direction;
    bool isDD;
protected slots:
    void move();
};

#endif // BULLET_H
