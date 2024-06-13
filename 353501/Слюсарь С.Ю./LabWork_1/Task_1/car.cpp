#include "car.h"

Car::Car() : Rectangle()
{
    rect = new Rectangle();
}

void Car::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Rectangle::paint(painter, option, widget);

    QPolygon pol, door;
    painter->setBrush(Qt::darkRed);
    painter->setPen(Qt::darkRed);
    painter->drawLine(400, 300, 500, 300);

    if (openDoor_ == 0)
    {
        door << QPoint(400, 200) << QPoint(500, 200) << QPoint(500, 300) << QPoint(400, 300);
        painter->drawPolygon(door);
        update();
    }
    else
    {
        door << QPoint(492, 200) << QPoint(500, 200) << QPoint(500, 300) << QPoint(492, 300);
        painter->drawPolygon(door);
        update();
    }

    painter->setPen(Qt::darkYellow);
    painter->setBrush(Qt::darkYellow);
    painter->drawRect(500, 200, 80, 100);

    painter->setPen(Qt::gray);
    painter->setBrush(Qt::gray);
    pol << QPoint(520, 200) << QPoint(500, 130) << QPoint(510, 130) << QPoint(530, 200);
    painter->drawPolygon(pol);

    painter->setPen(Qt::yellow);
    painter->setBrush(Qt::black);
    painter->drawEllipse(270, 290, 50, 50);
    painter->drawEllipse(500, 290, 50, 50);

    if (lightsOn_)
    {
        painter->setPen(Qt::white);
        painter->setBrush(Qt::white);
        painter->drawEllipse(575, 210, 10, 20);
        update();
    }
    else
    {
        painter->setPen(Qt::black);
        painter->setBrush(Qt::black);
        painter->drawEllipse(575, 210, 10, 20);
        update();
    }

}

void Car::lightsOnOff()
{
    if (lightsOn_ == 1)
    {
        lightsOn_ = 0;
    }
    else
    {
        lightsOn_ = 1;
    }
}

void Car::openDoor()
{
    if (openDoor_ == 1)
    {
        openDoor_ = 0;
    }
    else
    {
        openDoor_ = 1;
    }
}
void Car::move()
{
    if (stop <= 150) {
        moveBy(xspeed, 0);
        stop += 2;

    }
}

void Car::moveBack()
{
    if (stop >= -150) {
        moveBy(-xspeed,0);
        stop -= 2;
    }
}
