#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)  : QGraphicsItem(), QObject()
{
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::darkGreen);
    painter->setBrush(Qt::darkGreen);
    painter->drawRect(x_, y_, width_, height_);

}

QRectF Rectangle::boundingRect() const
{
    return QRectF(0, 0, 2000, 1000);
}

void Rectangle::move()
{
    if (x_ <= 100) {
        moveBy(xspeed, 0);
        x_ += 2;
    }
}

void Rectangle::moveBack()
{
    if (x_ >= -100) {
        moveBy(-xspeed, 0);
        x_ -= 2;
    }
}
