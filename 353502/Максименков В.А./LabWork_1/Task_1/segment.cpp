#include "segment.h"

Segment::Segment()
{
    setPos(400, 600);
}

QRectF Segment::boundingRect() const
{
    return QRectF(-50, -50, 150, 100);
}

void Segment::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawLine(A, B);
}

void Segment::advance(int phase)
{
    if (phase)
    {
        moveBy(0, -2 * v);
        v *= 1.05;
    }
}
