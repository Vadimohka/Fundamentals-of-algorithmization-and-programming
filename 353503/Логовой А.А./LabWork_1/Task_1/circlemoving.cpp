#include "circlemoving.h"
#include <QPainter>
#include <QWidget>
#include <QPoint>

CircleMoving::CircleMoving(){
    circle_ = QRectF(0,0,100,100);
    is_move = false;
    rotate_angle = 0;
}

QRectF CircleMoving::boundingRect() const{
    return circle_;
}

void CircleMoving::paint(QPainter *painter,const QStyleOptionGraphicsItem *, QWidget *){

}

void CircleMoving::move(){


    if(this->x() > 2000)
        this->setPos(this->x()-2200, this->y());

    if(is_move)
        this->setPos(this->x()+1 , this->y());

}

void CircleMoving::turnOn(){
    is_move = !is_move;

}
