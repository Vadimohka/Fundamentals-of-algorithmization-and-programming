#include "movingrectangle.h"

MovingRectangle::MovingRectangle()
{
    setRect(0, 0, 100, 50);
    setFlag(QGraphicsItem::ItemIsMovable);
}

void MovingRectangle::moveLeft()
{
    setPos(x()-10, y());
}

void MovingRectangle::moveRight()
{
    setPos(x()+10, y());
}
