#include "Rect.h"
#include <QPainter>
#include <QTimer>
#include "mainwindow.h"

Rect::Rect() : timer(new QTimer(this))
{

    timer->start(10);
    connect(timer, &QTimer::timeout, this, &Rect::turnLeft);
    connect(timer, &QTimer::timeout, this, &Rect::turnRight);
    x = 40;
    y = 40;
    rotate_right = 40;
    rotate_left = -40;
    ifLeft = false;
    ifRight = false;
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

void Rect::turnLeft()
{
    if (ifLeft && x > -40)
    {
        x--;
        rotate_left++;
        update();
    }
    if (!ifLeft && x < 40)
    {
        x++;
        rotate_left--;
        update();
    }
}

void Rect::turnRight()
{
    if (ifRight && y > -40)
    {
        y--;
        rotate_right--;
        update();
    }
    if (!ifRight && y < 40)
    {
        y++;
        rotate_right++;
        update();
    }
}

void Rect::setLeft()
{
    if(ifLeft) ifLeft = false; else ifLeft = true;
}

void Rect::setRight()
{
    if(ifRight) ifRight = false; else ifRight = true;
}