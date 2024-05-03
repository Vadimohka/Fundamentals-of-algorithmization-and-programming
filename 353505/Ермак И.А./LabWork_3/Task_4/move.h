#ifndef MOVE_H
#define MOVE_H

#include <QGraphicsItemAnimation>
#include <QStack>
#include <QGraphicsRectItem>
#include <QTimeLine>

class Move
{
public:
    Move();
    void Moves(QStack<QGraphicsRectItem*>[], int, int);
};

#endif // MOVE_H
