#include "flag.h"

Flag::Flag() {
}

QRectF Flag::boundingRect() const
{
    return QRectF(xpos, ypos, 100, 50);
}

void Flag::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush (Qt::yellow);

    painter->fillRect(rec,brush);
    painter->drawRect(rec);
}
