#include "sprite.h"

Sprite::Sprite() {}

void Sprite::draw(QPainter *painter)
{
    painter->drawPixmap(x, y, *image);
}

void Sprite::setCords(int x, int y)
{
    this->x = x;
    this->y = y;
}
