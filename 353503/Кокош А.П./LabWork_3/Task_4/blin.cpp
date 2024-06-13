#include "blin.h"

QRectF Blin::boundingRect() const
{
    return QRectF(0, 0, WIDTH_BLIN, HIGH_BLIN / num);
}

void Blin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setPen(Qt::darkRed);
    painter->setBrush(Qt::darkMagenta);
    painter->drawRect(0, 0, 175 - (125 / (num - 1) * (n - 1)), HIGH_BLIN / num);
}

Blin::Blin()
{
    n++;
}
