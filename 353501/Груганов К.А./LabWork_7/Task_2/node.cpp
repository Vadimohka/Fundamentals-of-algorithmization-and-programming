#include "node.h"
#include <QPainter>

Node::Node(int key, QString value)
    : key(key)
    , value(value)
{}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawEllipse(-10, -10, 20, 20);
    painter->drawText(boundingRect(), Qt::AlignCenter, QString::number(key));
}

QRectF Node::boundingRect() const
{
    return QRectF(-10, -10, 20, 20);
}
