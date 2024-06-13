#include "rocket.h"

Rocket::Rocket(int color) : color(color)
{
    setPos(400, 600);
}

void Rocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawLine(B, QPoint(10, 20));
    painter->drawLine(B, QPoint(-10, 20));
    painter->drawLine(QPoint(10, 20), QPoint(-10, 20));
    painter->setBrush(Qt::blue);
    painter->drawRect(-10, 20, 20, 30);
    painter->drawLine(QPoint(10, 50), QPoint(20, 70));
    painter->drawLine(QPoint(-10, 50), QPoint(-20, 70));
    painter->drawLine(QPoint(-20, 70), QPoint(20, 70));

    QPainterPath triangle;
    triangle.moveTo(B);
    triangle.lineTo(10, 20);
    triangle.lineTo(-10, 20);
    triangle.closeSubpath();
    painter->fillPath(triangle, Qt::red);

    QPainterPath fire;
    fire.moveTo(20, 71);
    fire.lineTo(40, 100);
    fire.lineTo(20, 90);
    fire.lineTo(30, 120);
    fire.lineTo(10, 100);
    fire.lineTo(0, 130);
    fire.lineTo(-10, 100);
    fire.lineTo(-30, 120);
    fire.lineTo(-20, 90);
    fire.lineTo(-40, 100);
    fire.lineTo(-20, 71);
    fire.closeSubpath();
    if (color == 1)
    {
        painter->fillPath(fire, Qt::red);
    }
    else
    {
        painter->fillPath(fire, Qt::white);
    }
}




