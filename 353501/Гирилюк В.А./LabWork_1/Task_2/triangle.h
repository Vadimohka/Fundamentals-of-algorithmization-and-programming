#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle: public Shape
{
public:
    QTimer *triangleTimer;
    QPointF *point;
    double sideA = 100, current_sideA = 100, sideB = 100, current_sideB = 100, sideC = 100, current_sideC = 100;
    Triangle(QGraphicsItem *parent = nullptr);
    ~Triangle();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void Resize();
    QRectF boundingRect() const;
};

#endif // TRIANGLE_H
