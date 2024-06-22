#ifndef RHOMB_H
#define RHOMB_H

#include "moveitem.h"

class Rhomb : public MoveItem
{
public:
    explicit Rhomb(QObject *parent = nullptr);
    qreal findPerimeter();
    qreal findSquare();

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Rhomb();
private:
    QPoint points[4];

};

#endif // RHOMB_H
