#include "movingcart.h"
#include "QPainter"

MovingCart::MovingCart()
{
    rect_ = QRectF(0, 0, 200, 90);
    angle_wheel = 0;
}


void MovingCart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //корпус
    painter->setBrush(Qt::blue);
    painter->drawRect(0, 0, 200, 60);
    //1 колесо
    painter->setBrush(Qt::red);
    painter->save();
    painter->translate(30, 60);
    painter->rotate(angle_wheel);
    painter->drawEllipse(-20, -20, 40, 40);
    painter->setBrush(Qt::black);
    painter->drawLine(0, -20, 0, 20);
    painter->drawLine(-20, 0, 20, 0);
    //2 колесо
    painter->restore();
    painter->save();
    painter->translate(170, 60);
    painter->rotate(angle_wheel);
    painter->drawEllipse(-20, -20, 40, 40);
    painter->setBrush(Qt::black);
    painter->drawLine(0, -20, 0, 20);
    painter->drawLine(-20, 0, 20, 0);
    painter->restore();

    angle_wheel += 3;
}
