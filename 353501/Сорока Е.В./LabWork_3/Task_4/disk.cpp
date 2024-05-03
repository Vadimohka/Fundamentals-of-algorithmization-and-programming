#include "disk.h"
#include <QPainter>

Ring::Ring(qreal width) : width(width)
{
}

QRectF Ring::boundingRect() const
{
    return QRectF(0, 0, width, 20);
}

void Ring::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QColor color = QColor(QColorConstants::Blue);

    QBrush brush(color);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

qreal Ring::getWidth() const
{
    return width;
}
