#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square: public Shape
{
public:
    QTimer *sqrTimer;
    double sideA = 100, current_sideA = 100;
    Square(QGraphicsItem *parent = nullptr);
    ~Square();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void Resize();
    QRectF boundingRect() const;
};

#endif // SQUARE_H
