#ifndef STAR_8_H
#define STAR_8_H

#include "shape.h"

class Star_8 : public Shape
{
public:
    explicit Star_8(QPointF);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    qreal GetSquare();
    qreal GetPerimetr();
    QPointF GetCenter();
};


#endif // STAR_8_H
