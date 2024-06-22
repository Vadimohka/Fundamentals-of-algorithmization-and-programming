#ifndef STAR5_H
#define STAR5_H

#include "moveitem.h"

class Star5 : public MoveItem
{
public:
    explicit Star5(QObject *parent = nullptr);
    qreal findPerimeter();
    qreal findSquare();

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Star5();
private:
    QPoint points[10];
};

#endif // STAR5_H
