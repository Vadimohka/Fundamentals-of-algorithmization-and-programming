#ifndef RING_H
#define RING_H

#include <QtWidgets>

class Ring : public QGraphicsRectItem
{
public:
    Ring(int size, QColor color)
        : QGraphicsRectItem(0, 0, 200 - size * 20, 30)
    {
        setBrush(color);
    }
};

#endif // RING_H
