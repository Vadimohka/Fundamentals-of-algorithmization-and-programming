//
// Created by darina on 4/10/24.
//

#include "Rectangle.h"

QRectF Rectangle::boundingRect() const {
    return {0, 0, 0, 0};
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::yellow);
    painter->setPen(Qt::black);
    painter->drawRect(x, y, w, h);

}

Rectangle::Rectangle(double x0, double y0, double height) {
    x = x0;
    y = y0;
    h = height;
    update();
}

int Rectangle::getX() const {
    return x;
}

int Rectangle::getY() const {
    return y;
}

int Rectangle::getH() const {
    return h;
}

