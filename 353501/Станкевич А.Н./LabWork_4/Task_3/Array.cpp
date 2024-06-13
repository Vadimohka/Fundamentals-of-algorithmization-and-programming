#include "Array.h"
#include <QPainter>
#include <QTimer>

Array::Array()
{
}

Array::~Array()
{
}

QRectF Array::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void Array::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int width = 500, hight = 500;
    painter->setPen(Qt::gray);
    for(int i = 0; i < number; i++) {
        painter->drawRect(i * width / number, 0, width / number, (1 + i) * (hight / number));
    }
}
