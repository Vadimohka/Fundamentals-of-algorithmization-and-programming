#include "ground.h"

Ground::Ground()
{

}

void Ground::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);

    painter->setBackgroundMode(Qt::BGMode::OpaqueMode);
    QBrush brush(Qt::green);
    painter->setBrush(brush);

    painter->drawRect(-100, 500, 800, 400);
}
