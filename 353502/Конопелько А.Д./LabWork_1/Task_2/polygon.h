#ifndef POLYGON_H
#define POLYGON_H

#include <QVector>
#include "moveitem.h"

class Polygon : public MoveItem
{
public:
    explicit Polygon(int& newAmount);
    qreal findPerimeter();
    qreal findSquare();

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Polygon();
private:
    int amount = 6;
};

#endif // POLYGON_H
