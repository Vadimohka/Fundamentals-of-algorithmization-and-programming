#ifndef STAR_5_H
#define STAR_5_H

#include "shape.h"

class Star_5 : public Shape
{
public:
    explicit Star_5(QPointF);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    qreal GetSquare();
    qreal GetPerimetr();
    QPointF GetCenter();
};

#endif // STAR_5_H
