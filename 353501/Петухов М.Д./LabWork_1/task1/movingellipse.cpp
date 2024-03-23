#include "movingellipse.h"

Movingellipse::Movingellipse(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : QGraphicsEllipseItem(x, y, width, height, parent) {
    coordinates=pos();
    coordY = 0;
}


void Movingellipse::move(){
    coordinates.setY(coordY);
    setPos(coordinates);
}

void Movingellipse::startFly(){
    if(!isBursted){
        connect(timer, &QTimer::timeout, this, &Movingellipse::flyUp);
        timer->start(35);
    }
}
void Movingellipse::flyUp(){
    if(coordY > -400){
        coordY-=5;
        move();
    }
}
void Movingellipse::stopFly(){
    disconnect(timer, &QTimer::timeout, this, &Movingellipse::flyUp);
    timer->stop();
}


void Movingellipse::startFlyDown(){
    if(!isBursted){
        connect(timer, &QTimer::timeout, this, &Movingellipse::flyDown);
        timer->start(35);
    }
}
void Movingellipse::flyDown(){
    if(coordY < 400){
        coordY+=5;
        move();
    }
}
void Movingellipse::stopFlyDown(){
    disconnect(timer, &QTimer::timeout, this, &Movingellipse::flyDown);
    timer->stop();
}
