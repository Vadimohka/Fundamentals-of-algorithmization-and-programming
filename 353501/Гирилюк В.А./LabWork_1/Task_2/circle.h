#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle: public Shape
{
public:
    QTimer *circleTimer;
    double sideA = 100, current_sideA = 100;
    Circle(QGraphicsItem *parent = nullptr);
    ~Circle();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void Resize();
    QRectF boundingRect() const;
};

#endif // CIRCLE_H
