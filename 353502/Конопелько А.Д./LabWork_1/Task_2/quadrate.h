#ifndef QUADRATE_H
#define QUADRATE_H

#include "moveitem.h"

class Quadrate : public MoveItem
{
public:
    explicit Quadrate(QObject *parent = nullptr);
    qreal findPerimeter();
    qreal findSquare();

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Quadrate();
private:
    QPoint points[4];

};
#endif // QUADRATE_H
