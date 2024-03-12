#include "Rect.h"
#include <QPainter>
#include <QTimer>
#include "mainwindow.h"

Rect::Rect() : timer(new QTimer(this))
{

    timer->start(50);
    connect(timer, &QTimer::timeout, this, &Rect::onTimer);
    x = 0;
    left = 0;
    y = 0;
    rotate_right = 0;
    rotate_left = 0;
}

QRectF Rect::boundingRect() const
{

    return QRectF(0, 0, 10, 10);
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::black);
    painter->drawRect(+43, 50 + y, +07, 65);

    painter->setBrush(Qt::red);
    painter->drawRect(+43, 50 + y, +50, 30);

    painter->setBrush(Qt::black);
    painter->drawRect(-43, 50 + x, -07, 65);
    
    painter->setBrush(Qt::green);
    painter->drawRect(-43, 50 + x, -50, 30);


    painter->setBrush(Qt::black);

    painter->save();
    painter->translate(0, 90);
    painter->rotate(rotate_right);
    painter->drawRect(0, 0, +65, 7);
    painter->restore();

    painter->save();
    painter->translate(0, 90);
    painter->rotate(rotate_left);
    painter->drawRect(0, 0, -65, 7);
    painter->restore();
}

void Rect::onTimer()
{
    // if (x < 180) {
    // x++;
    // update();
    // }
}

void Rect::turnLeft()
{
    if (left == 0)
    {
        x = -40;
        rotate_left = 45;
    }
    else if (left == 1)
    {
        x = 0;
        rotate_left = 0;
    }
    else if (left == 2)
    {
        x = 40;
        rotate_left = -45;
    }
    else if (left == 3)
    {
        x = 0;
        rotate_left = 0;
    }
    left++;
    left %= 4;
    update();
}

void Rect::turnRight()
{
    if (right == 0)
    {
        y = -40;
        rotate_right = -45;
    }
    else if (right == 1)
    {
        y = 0;
        rotate_right = 0;
    }
    else if (right == 2)
    {
        y = 40;
        rotate_right = +45;
    }
    else if (right == 3)
    {
        y = 0;
        rotate_right = 0;
    }
    right++;
    right %= 4;
    update();
}