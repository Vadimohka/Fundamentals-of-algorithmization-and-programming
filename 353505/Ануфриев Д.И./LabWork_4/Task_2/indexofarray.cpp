#include "indexofarray.h"

IndexOfArray::IndexOfArray(qreal pos_x, qreal pos_y, qreal width, qreal height, QColor color)
{
    this->width = width;
    this->height = height;

    this->color = color;

    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

void IndexOfArray::setColor(QColor color)
{
    this->color = color;
    this->update();
}

void IndexOfArray::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);
    painter->drawRect(boundingRect());

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF IndexOfArray::boundingRect() const
{
    return QRectF(pos_x, pos_y, width, height);
}
