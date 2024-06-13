#include "disk.h"

Disk::Disk()
{
    timer = new QTimer();
    timer->setInterval(1);
    connect(timer, &QTimer::timeout, this, &Disk::move);
}

QRectF Disk::boundingRect() const
{
    return QRectF(0,0,width,height);
}

void Disk::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(Qt::white);
    painter->drawRect(0,0,width,height);
}

void Disk::setParams(int height, int width)
{
    this->height = height;
    this->width = width;
}

void Disk::moveTo(int x, int y)
{
    timer->start();
    moveToX = x;
    moveToY = y;

}

void Disk::move()
{
    qreal current_X = pos().x();
    qreal current_Y = pos().y();
    if (moveToX != current_X){
        if(current_X < moveToX && abs(moveToX - current_X) > 3){
            current_X+=3;
        }
        else if(current_X > moveToX && abs(current_X - moveToX) > 3){
            current_X-=3;
        }
        else{
            current_X = moveToX;
            timer->stop();
        }
        setPos(current_X, current_Y);
    }
    else if(current_Y != moveToY){
        if(current_Y < moveToY && abs(moveToY - current_Y) > 3){
            current_Y+=3;
        }
        else if(current_Y > moveToY && abs(current_Y - moveToY) > 3){
            current_Y-=3;
        }
        else{
            current_Y = moveToY;
            timer->stop();
        }
        setPos(current_X, current_Y);
    }
}
