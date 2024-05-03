#ifndef STAR_6_H
#define STAR_6_H

#include "shape.h"

class Star_6 : public Shape
{
public:
    explicit Star_6(QPointF);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    qreal GetSquare();
    qreal GetPerimetr();
    QPointF GetCenter();
};

#endif // STAR_6_H
