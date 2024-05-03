#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class Ellipse: public Shape
{
public:
    QTimer *ellTimer;
    double sideA = 100, sideB = 50, current_sideA = 100, current_sideB = 50;
    Ellipse(QGraphicsItem *parent = nullptr);
    ~Ellipse();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void Resize();
    QRectF boundingRect() const;
};

#endif // ELLIPSE_H
