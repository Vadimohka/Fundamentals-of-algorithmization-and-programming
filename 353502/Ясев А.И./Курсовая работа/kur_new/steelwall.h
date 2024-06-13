#ifndef STEELWALL_H
#define STEELWALL_H

#include "square.h"


class SteelWall : public Square
{

public:
    SteelWall(qint8 x, qint8 y, QGraphicsObject *parent = 0);
protected:
    qint8 x;
    qint8 y;
};

#endif // STEELWALL_H
