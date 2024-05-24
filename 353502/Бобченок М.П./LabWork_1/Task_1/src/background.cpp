//
// Created by u on 09.03.24.
//

#include "background.h"

QRectF background::boundingRect() const
{
    return {0, 0, 0, 0};
}

void background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap background("../src/background.jpg");
    background = background.scaled(2560, 1600);
    painter->drawPixmap(-2560/2, -1600/2, background);
}
