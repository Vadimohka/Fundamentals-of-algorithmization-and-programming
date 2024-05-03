#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
public:
    Circle(qreal radius, QGraphicsItem *parent = nullptr);

protected:
    void calculate_points();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal area() override;
    qreal perimeter() override;

private:
    qreal radius;
};

#endif // CIRCLE_H
