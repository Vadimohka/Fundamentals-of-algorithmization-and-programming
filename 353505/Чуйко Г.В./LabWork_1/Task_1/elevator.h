// elevator.h
#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "rectangle.h"

class Elevator : public Rectangle
{
private:
    qreal m_width;
    qreal m_height;

public:
    Elevator(qreal width, qreal height, Rectangle *parent = nullptr)
        : Rectangle(parent), m_width(width), m_height(height) {}

    QRectF boundingRect() const override;

    void setDimensions(qreal width, qreal height);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;


};

#endif // ELEVATOR_H

