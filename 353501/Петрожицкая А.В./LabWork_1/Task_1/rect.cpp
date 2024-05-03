#include "rect.h"
#include<QPainter>
#include<QTimer>

Rect::Rect() {
    timerToFirst = new QTimer;
    connect(timerToFirst, &QTimer::timeout, this, &Rect::moveToFirst);

    timerToSecond = new QTimer;
    connect(timerToSecond, &QTimer::timeout, this, &Rect::moveToSecond);

    timerToThird = new QTimer;
    connect(timerToThird, &QTimer::timeout, this, &Rect::moveToThird);

    x = 0;
    y = -100;
    minY = 50;
    midY = -150;
    maxY = -350;
}

QRectF Rect::boundingRect() const{
    return QRectF(0, 0, 10, 10);
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawRect(-100, y - x, 200, 300);
    painter->setBrush(Qt::yellow);
        painter->setPen(QPen(Qt::yellow, 3));
    painter->drawEllipse(-20, 150 + y - x, 30, 30);
    painter->drawLine(-5, 180 + y - x, -5, 250 + y-x);
    painter->drawLine(-5, 250 + y - x, -20, 300 + y-x);
    painter->drawLine(-5, 250 + y - x, 10, 300 + y-x);
    painter->drawLine(-5, 195 + y - x, -20, 235 + y-x);
    painter->drawLine(-5, 195 + y - x, 10, 235 + y-x);

}

void Rect::moveToFirst(){
    timerToFirst->start(15);
    x -=1;
    if((y-x)<=minY && (y-x)>=maxY){
        update();
    }
    else{
        timerToFirst->stop();
    }
}

void Rect::moveToSecond(){
    timerToSecond->start(15);
    if((y-x)>midY){
        x+=1;
        if((y-x)>=midY && (y-x)<=minY){
            update();
        }
        else{
            timerToSecond->stop();
        }
    }
    else if((y-x)<midY){
        x -=1;
        if((y-x)<=midY && (y-x)>=maxY){
            update();
        }
        else{
            timerToSecond->stop();
        }
    }
    else{
        timerToSecond->stop();
    }
}

void Rect::moveToThird(){
    timerToThird->start(15);
    x +=1;
    if((y-x)>=maxY && (y-x)<=minY){
        update();
    }
    else{
        timerToThird->stop();
    }
}
