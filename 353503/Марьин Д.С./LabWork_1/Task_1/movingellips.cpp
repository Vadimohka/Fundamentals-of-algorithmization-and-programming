#include "movingellips.h"

MovingEllips::MovingEllips(QObject *parent,QRectF ellips,QColor color)
    : QObject{parent},QGraphicsItem(),ellips(ellips),color(color)
{
    this->ellips.getRect(&x,&y,&width,&height);
}

QColor MovingEllips::get_color()
{
    return color;
}

QRectF MovingEllips::get_Rect()
{
    return ellips;
}

qreal MovingEllips::get_x()
{
    return x;
}

qreal MovingEllips::get_y()
{
    return y;
}

qreal MovingEllips::get_width()
{
    return width;
}

qreal MovingEllips::get_height()
{
    return height;
}

QRectF MovingEllips::boundingRect() const
{
    return ellips;
}
