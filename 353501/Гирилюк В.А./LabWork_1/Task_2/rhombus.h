#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "shape.h"

class Rhombus: public Shape
{
public:
    QTimer *rhombTimer;
    double diagA = 100, diagB = 50, current_diagA = 100, current_diagB = 50;
    Rhombus(QGraphicsItem *parent = nullptr);
    ~Rhombus();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void Resize();
    QRectF boundingRect() const;
};

#endif // RHOMBUS_H
