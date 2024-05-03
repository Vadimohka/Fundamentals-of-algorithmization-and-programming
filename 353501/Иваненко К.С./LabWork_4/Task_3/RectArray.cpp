#include "RectArray.h"
#include <QPainter>
#include <QTimer>
#include "mainwindow.h"

RectArray::RectArray()
{
}

RectArray::~RectArray()
{
}

QRectF RectArray::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void RectArray::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::gray);
    int width = 500, hight = 500;

    for(int i = 0; i < number; i++) {
        painter->drawRect(i * width / number, 0, width / number, (1 + i) * (hight / number));
    }
}