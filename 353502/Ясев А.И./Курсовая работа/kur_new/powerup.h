#ifndef POWERUP_H
#define POWERUP_H

#include "square.h"


class PowerUp : public Square
{
public:
    PowerUp(qint8 x, qint8 y, QGraphicsObject *parent = 0);
    ~PowerUp();
    enum Type{
        HEAL = 0,
        DOUBLEDAMAGE = 1,
        GHOST = 2
    };
    Type getType();
private:
Type type;
};

#endif // POWERUP_H
