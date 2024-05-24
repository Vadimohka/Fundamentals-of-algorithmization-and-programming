#include "figure.h"

Figure::Figure(){

}

QRectF Figure::boundingRect() const{
    return QRectF(-500,-500,1000,1000);
}

float Figure::getScale(){
    return scale;
}

QPoint Figure::getCenter(){
    return QPoint(this->x(), this->y());
}

bool Figure::getItem(){
    return Flag;
}

void Figure::setItem(bool flag){
    Flag=flag;
}

void Figure::getSize(){
    if(this->getItem()){
        scale += 0.01;
    }else{
        scale -= 0.01;
        if(scale < 0){
            scale=0.01;
        }
    }

    this->setScale(scale);
}

void Figure::move_up(){
    this->setPos(this->x(), this->y() - 2);
    if(this->y()<-360){
        this->setPos(this->x(), -360);
    }
}

void Figure::move_down(){
    this->setPos(this->x(), this->y() + 2);
    if(this->y()>440){
        this->setPos(this->x(), 440);
    }
}

void Figure::move_left(){
    this->setPos(this->x() - 2 , this->y());
    if(this->x()<-1040){
        this->setPos(-1040, this->y());
    }
}

void Figure::move_right()
{
    this->setPos(this->x() + 2, this->y());
    if(this->x()>1050){
        this->setPos(1050, this->y());
    }
}

void Figure::rotate_right(){
    ++angle;
    this->setRotation(angle);
}

void Figure::rotate_left(){
    --angle;
    this->setRotation(angle);
}


void Figure::move(){
    QPoint dif = mouseMoveNow - mouseMovePress;
    for (auto &point: points){
        point += dif;
    }
    mouseMovePress = mouseMoveNow;
}

void Figure::mousePressing(QMouseEvent *me){
    mousePress = me->pos();
    mouseNow = me->pos();
}

void Figure::mouseMovePressing(QMouseEvent *me){
    mouseMovePress = me->pos();
}

void Figure::mouseMoving(QMouseEvent *me){
    mouseNow = me->pos();
    setPoints(me);
}

void Figure::mouseMoveMoving(QMouseEvent *me){
    mouseMoveNow = me->pos();
    move();
}

float Figure::area(){
    return 0;
}

float Figure::perimeter(){
    return 0;
}

void Figure::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *){

}

void Figure::setPoints(QMouseEvent *){

}
