//
// Created by darina on 4/10/24.
//

#include "MovingRectangle.h"

QRectF MovingRectangle::boundingRect() const {
    return {0, 0, 0, 0};
}

void MovingRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::yellow);
    painter->setPen(Qt::black);
    painter->drawRect(x, y, w, h);

}

MovingRectangle::MovingRectangle(double x0, double y0, double width) {
    x = x0;
    y = y0;
    w = width;
}

void MovingRectangle::move(int x, int y) {

    this->x += x;
    this->y += y;
    update();
}

int MovingRectangle::getX() {
    return x;
}

int MovingRectangle::getY() {
    return y;
}

int MovingRectangle::getW() {
    return w;
}

