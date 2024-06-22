#ifndef STAR6_H
#define STAR6_H

#include "moveitem.h"

class Star6 : public MoveItem
{
public:
    explicit Star6(QObject *parent = nullptr);
    qreal findPerimeter();
    qreal findSquare();

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Star6();
private:
    QPoint points[12];
};

#endif // STAR8_H
