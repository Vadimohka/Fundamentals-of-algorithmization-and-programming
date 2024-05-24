#include "movingcircle.h"

MovingCircle::MovingCircle(){
    setFlag(QGraphicsItem::ItemIsMovable);
}

void MovingCircle::moveLeft(){
    setPos(x()-20,y());
    xc-=20;
}

void MovingCircle::moveRight(){
    setPos(x()+20,y());
    xc+=20;
}

void MovingCircle::moveDown(){
    setPos(x(),y()+20);
    yc+=20;
}

void MovingCircle::moveUp(){
    setPos(x(),y()-20);
    yc-=20;
}
