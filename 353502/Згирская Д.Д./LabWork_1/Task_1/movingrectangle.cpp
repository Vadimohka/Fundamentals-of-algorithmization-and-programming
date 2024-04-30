#include "movingrectangle.h"

MovingRectangle::MovingRectangle(QWidget *parent)
    : QWidget{}
{
    this->setParent(parent);
    this->timer->setInterval(10);
}


void MovingRectangle::paintEvent(QPaintEvent *event) {
    QPainter *painter = new QPainter;
    painter->begin(this);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::red);
    QRect rectangle(QPoint(10,10),QPoint(30,50));
    painter->drawRect(rectangle);
    painter->end();
}


void MovingRectangle::MoveRectangle()
{
    timer->start();

    MovingRectangle::connect(timer,SIGNAL(timeout()),this,SLOT(Up()));
}


void MovingRectangle::StopMove()
{
    timer->stop();

    MovingRectangle::disconnect(timer,SIGNAL(timeout()),this,SLOT(Up()));
}


void MovingRectangle::Up(){
    static int movement = 0;
    if(movement < 250)
    {
        this->move(this->x(),this->y()-1);
        ++movement;
    }
}



