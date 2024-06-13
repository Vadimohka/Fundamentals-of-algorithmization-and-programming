


































#ifndef ALL_SHAPES_H
#define ALL_SHAPES_H
#pragma once
#include <QObject>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QGraphicsSceneMouseEvent>
#include <QLineEdit>
#include <QTimer>
#include <math.h>
#include <QGraphicsEllipseItem>



class All_shapes
{
public:

    QPointF Mouse_last_pos;
    enum Item {None, RECT, SQUARE, TRIANGLE, RHOMB, STAR_5, STAR_6, STAR_8, HEXAGON, CIRCLE};
    Item item = None;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent*) ;
    void mousePressEvent(QGraphicsSceneMouseEvent*) ;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);


private:
public:
    All_shapes();
    \

protected:
//    QRectF boundingRect() const;
//    virtual void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    \
};

#endif // ALL_SHAPES_H
