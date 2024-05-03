#include "mrectangle.h"

Mrectangle::Mrectangle(){

}

void Mrectangle::rotateL(){
    QPointF rotationPoint (0,0);
    this->setTransformOriginPoint(rotationPoint);
    rotationAngle -= 10;
    this->setRotation(rotationAngle);
}

void Mrectangle::rotateR(){
    QPointF rotationPoint (0,0);
    this->setTransformOriginPoint(rotationPoint);
    rotationAngle += 10;
    this->setRotation(rotationAngle);
}
QRectF Mrectangle::boundingRect() const{
    return QRectF(0,0,100,100);
}


void Mrectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //QRectF rect = boundingRect();
    painter->drawRect(0, 0, 50, 100);
}

