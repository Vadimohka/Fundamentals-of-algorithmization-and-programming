#include "cart.h"

Cart::Cart() {
    rect = new Rectangle;
    circle1 = new Circle;
    circle2 = new Circle;

    QColor color = QColor(0,0,0);
    circle1->setBrush(color);
    circle2->setBrush(color);
    circle1->setRect(0,490,20,20);
    circle2->setRect(200,490,20,20);
    animationTimer = new QTimer;
}

void Cart::advance(int phase)
{
    if(phase)
    {
        moveBy(xspeed,0);
    }
}

void Cart::speed(int speedVal)
{
    animationTimer->start(1000/(60+speedVal*2));
}

void Cart::stop()
{
    animationTimer->stop();
}

QGraphicsItemGroup *Cart::returnCartGroup(QGraphicsItemGroup *group)
{
    group->addToGroup(rect);
    group->addToGroup(circle1);
    group->addToGroup(circle2);

    return group;
}









