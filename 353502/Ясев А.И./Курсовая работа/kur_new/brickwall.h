#ifndef BRICKWALL_H
#define BRICKWALL_H

#include "steelwall.h"


class BrickWall : public SteelWall
{
    Q_OBJECT
public:
    BrickWall(qint8 x, qint8 y, QGraphicsObject *parent = 0);
    ~BrickWall();
    void takeDamage(qint8 damage);
private:
    qint8 hp = 3;
signals:
    void onDeath(Square::Cell cell);
};

#endif // BRICKWALL_H
