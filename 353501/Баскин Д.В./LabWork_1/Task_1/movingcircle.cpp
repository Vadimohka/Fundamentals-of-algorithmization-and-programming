#include "movingcircle.h"

MovingCircle::MovingCircle()
{

}

void MovingCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::gray);
    painter->drawEllipse(-138, -138, 276, 276);
}

void MovingCircle::moveLeft()
{
    setPos(x()-5, y());
}

void MovingCircle::moveRight()
{
    setPos(x()+5, y());
}
