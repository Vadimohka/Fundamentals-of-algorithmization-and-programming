#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle: public Shape
{
public:
    QTimer *rectTimer;
    double sideA = 100, sideB = 50, current_sideA = 100, current_sideB = 50;
    Rectangle(QGraphicsItem *parent = nullptr);
    ~Rectangle();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void Resize();
    QRectF boundingRect() const;
};

#endif // RECTANGLE_H
