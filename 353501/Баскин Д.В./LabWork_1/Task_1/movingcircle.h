#ifndef MOVINGCIRCLE_H
#define MOVINGCIRCLE_H

#include <QObject>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class MovingCircle : public QGraphicsEllipseItem
{
public:
    MovingCircle();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void moveLeft();
    void moveRight();
};

#endif // MOVINGCIRCLE_H
