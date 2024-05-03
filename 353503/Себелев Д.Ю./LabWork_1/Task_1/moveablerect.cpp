#include "moveablerect.h"

MoveableRect::MoveableRect(QGraphicsObject *parent) : QGraphicsObject(parent)
{
    rect = new QRect();
}

MoveableRect::MoveableRect(int x, int y, int w, int h, QGraphicsObject *parent) : QGraphicsObject(parent)
{
    rect = new QRect(x, y, w, h);
}

MoveableRect::MoveableRect(int x, int y, int w, int h, QColor color, QGraphicsObject *parent) : QGraphicsObject(parent)
{
    rect = new QRect(x, y, w, h);
    rect_color = color;
}

QRectF MoveableRect::boundingRect() const
{
    return QRectF(0, -50, 140, 50);
}

void MoveableRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(rect_color);
    painter->drawRect(*rect);
}

void MoveableRect::rotate()
{
    setRotation(angle);
}
