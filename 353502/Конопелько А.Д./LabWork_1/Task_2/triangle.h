#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "moveitem.h"

class Triangle : public MoveItem
{
public:
    explicit Triangle(QObject *parent = nullptr);
    qreal findPerimeter();
    qreal findSquare();

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Triangle();
private:
    QPoint points[3];
};

#endif // TRIANGLE_H
