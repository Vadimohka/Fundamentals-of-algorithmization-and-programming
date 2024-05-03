#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QGraphicsView>

class Rectangle: public QGraphicsRectItem
{
public:
    Rectangle();
    QGraphicsRectItem *rect;

public slots:
    virtual void advance(int phase);
    int xspeed = 2 ;
};

#endif // RECTANGLE_H
