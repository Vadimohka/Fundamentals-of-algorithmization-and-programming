#ifndef MOVER_H
#define MOVER_H

#include <QGraphicsItemAnimation>
#include <QStack>
#include <QGraphicsRectItem>
#include <QTimeLine>

class Mover
{
public:
    Mover();
    void Move(QStack<QGraphicsRectItem*>[],
              int, int);
};

#endif // MOVER_H
