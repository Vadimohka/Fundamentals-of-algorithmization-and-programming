#ifndef STAR8_H
#define STAR8_H

#include "moveitem.h"

class Star8 : public MoveItem
{
public:
    explicit Star8(QObject *parent = nullptr);
    qreal findPerimeter();
    qreal findSquare();

    // QGraphicsItem interface
public:
    //virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Star8();
private:
    QPoint points[16];
};

#endif // STAR8_H
