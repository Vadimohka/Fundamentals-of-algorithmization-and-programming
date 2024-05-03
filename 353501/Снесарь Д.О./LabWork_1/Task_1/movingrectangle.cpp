#include "movingrectangle.h"

MovingRectangle::MovingRectangle()
{

}

void MovingRectangle::rotateL(){
    this->setTransformOriginPoint(boundingRect().center());
    this->setRotation(rotation() - 1);
}

void MovingRectangle::rotateR(){
    this->setTransformOriginPoint(boundingRect().center());
    this->setRotation(rotation() + 1);
}
/*QRectF MovingRectangle::boundingRect() const{
    return QRectF(0,0,120,120);
}


void MovingRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //QRectF rect = boundingRect();
    painter->drawRect(0, 0, 50, 50);
}*/
