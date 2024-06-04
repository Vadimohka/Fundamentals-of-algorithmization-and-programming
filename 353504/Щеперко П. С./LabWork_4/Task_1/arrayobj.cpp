#include "arrayobj.h"

int* ArrayObj::arr = new int[70]();

ArrayObj::ArrayObj()
{
    arr = new int[70]();
}

QRectF ArrayObj::boundingRect() const
{
    return QRect(0, 0, 1400, 800);
}

void ArrayObj::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(Qt::GlobalColor::green);
    painter->drawRect(0 + 20 * index, 800, 20, -arr[index]);
}
