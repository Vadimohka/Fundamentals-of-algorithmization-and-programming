//
// Created by u on 09.03.24.
//

#include <iostream>
#include "moving_rect.h"

void moving_rect::moveLeft()
{
    cur_speed -= 3;
    if (cur_speed > 1000)
        cur_speed = 1000;
    if (cur_speed < -1000)
        cur_speed = -1000;
}

void moving_rect::moveRight()
{
    cur_speed += 3;
    if (cur_speed > 1000)
        cur_speed = 1000;
    if (cur_speed < -1000)
        cur_speed = -1000;
}

void moving_rect::decreaseSpeed()
{
    if (cur_speed > 0)
        cur_speed--;
    else if (cur_speed < 0)
        cur_speed++;
}

void moving_rect::moveRect()
{
    move(x_pos + cur_speed, y_pos);
}

void moving_rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->setPen(Qt::black);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(15);
    painter->setPen(pen);
    painter->drawRect(x_pos, y_pos, w, h);
    update();
}

QRectF moving_rect::boundingRect() const
{
    return {0, 0, 0, 0};
}

void moving_rect::move(int x, int y)
{
    x_pos = x;
    y_pos = y;

    if (x_pos < -2200)
        x_pos = 1700;

    if (x_pos > 1700)
        x_pos = -2200;

    update();
}

moving_rect::moving_rect()
{
    x_pos = 0;
    y_pos = 0;
    w = 0;
    h = 0;
}

moving_rect::moving_rect(int x, int y, int _w, int _h)
{
    x_pos = x;
    y_pos = 0;
    w = _w;
    h = _h;
}
