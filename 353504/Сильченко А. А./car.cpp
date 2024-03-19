#include "car.h"
#include <QPainter>

Car::Car()
{
    mov=0;
    r=0;
    y1=0.0;
}

void Car::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    drawCar(&painter);
}

void Car::drawCar(QPainter *painter)
{
    draw(painter);
    //painter->drawLine(300, 370, 400, 370);
    //painter->drawLine(300, 430, 400, 430);
    painter->setBrush(QBrush(Qt::gray, Qt::SolidPattern));
    mov++;
    painter->drawRect(300+mov, 370, 100, 60);
    //qDebug()<<mov;
    //painter->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    painter->drawEllipse(300, 300, 20, 10);
    painter->drawEllipse(380, 300, 20, 10);
}

void Car::drawLight(QPainter *painter)
{
    //draw(painter);
    if(lighton)
        painter->setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    else
        painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter->drawEllipse(300, 300, 20, 10);
    painter->drawEllipse(380, 300, 20, 10);
    //painter->draw
}

void Car::drawDoors(QPainter *painter)
{
    //draw(painter);
    painter->drawLine(300, 370, 300-r, 430+y1);
    painter->drawLine(400, 370, 400+r, 430+y1);
}

void Car::light()
{
    lighton=!lighton;
}

bool Car::door()
{
    if(opened)
    {
        y1+=0.1;
        if(r>0)
        {
            r--;
        return true;y1+=0.5;
        }
    else
        return false;
    }
    else
    {
        y1-=0.1;
        if(r<=35)
    {
        r++;

            return true;
    }
        else
        return false;
    }
}

int Car::get_mov()
{
    return mov;
}

void Car::open()
{
    //qDebug()<<mov<<"IOPEN";

    opened=!opened;
    //qDebug()<<mov<<"IIOPEN";
}
