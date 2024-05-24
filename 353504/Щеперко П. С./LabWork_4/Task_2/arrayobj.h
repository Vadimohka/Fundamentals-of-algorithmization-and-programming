#ifndef ARRAYOBJ_H
#define ARRAYOBJ_H

#include <QGraphicsItem>
#include <QPainter>

class ArrayObj : public QGraphicsItem
{
public:
    static int *arr;
    ArrayObj();
    int value;
    int index;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ARRAYOBJ_H
