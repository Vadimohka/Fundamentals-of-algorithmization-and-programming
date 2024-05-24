//
// Created by u on 09.03.24.
//

#include <iostream>
#include "moving_rect.h"


void moving_rect::move(int speedX, int speedY, int posX, int posY)
{

}

void moving_rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (color)
    {
        case 0:
            painter->setBrush(Qt::red);
            break;
        case 1:
            painter->setBrush(Qt::yellow);
            break;
        case 2:
            painter->setBrush(Qt::gray);
            break;
        case 3:
            painter->setBrush(Qt::black);
            break;
    }

    painter->setPen(Qt::black);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(3);
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

    update();
}

int moving_rect::getX()
{
    return x_pos;
}

int moving_rect::getY()
{
    return y_pos;
}

int moving_rect::getW()
{
    return w;
}

int moving_rect::getH()
{
    return h;
}

void moving_rect::setX(int x)
{
    x_pos = x;
}

void moving_rect::setY(int y)
{
    y_pos = y;
}

moving_rect::moving_rect()
{
    x_pos = 0;
    y_pos = 0;
    w = 0;
    h = 0;
    color = 0;
}

moving_rect::moving_rect(moving_rect &&other)
{
    w = other.w;
    h = other.h;
    x_pos = other.x_pos;
    y_pos = other.y_pos;
    color = other.color;
};

moving_rect::moving_rect(int x, int y, int w, int h, int color) : x_pos(x), y_pos(y), w(w), h(h), color(color) {}
