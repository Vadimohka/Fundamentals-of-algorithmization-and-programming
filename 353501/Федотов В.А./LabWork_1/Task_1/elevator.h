#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "rectangle.h"

class Elevator : public Rectangle
{
    Q_OBJECT
public:
    Elevator();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

};
#endif // ELEVATOR_H
