#include "moving_rectangle.h"

MovingRectangle::MovingRectangle() {
    setRect(0, 0, 200, 100);
    setFlag(QGraphicsItem::ItemIsMovable);
}

void MovingRectangle::moveLeft() {
    setPos(x()-1, y());
}

void MovingRectangle::moveRight() {
    setPos(x()+1, y());
}

void MovingRectangle::moveDown() {
    setPos(x(), y()+1);
}

void MovingRectangle::moveUp() {
    setPos(x(), y()-1);
}
