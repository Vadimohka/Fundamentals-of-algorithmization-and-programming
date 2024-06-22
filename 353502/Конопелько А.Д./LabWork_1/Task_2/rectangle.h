#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "moveitem.h"

class Rectangle : public MoveItem
{
public:
    explicit Rectangle(QObject *parent = nullptr);
    qreal findPerimeter();
    qreal findSquare();

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Rectangle();
private:
    QPoint points[4];
};

#endif // RECTANGLE_H
