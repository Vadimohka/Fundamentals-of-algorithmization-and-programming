#include "rotatablecircle.h"

RotatableCircle::RotatableCircle() : MovingCircle(){
    circle = new QGraphicsEllipseItem(0,0,100,100,this);
    radius = new QGraphicsLineItem(15,15,50,50,this);
    circle->setBrush(Qt::green);
}

void RotatableCircle::rotate(){
    angle+=15;
    circle->setTransformOriginPoint(QPoint(circle->x()+50,circle->y()+50));
    radius->setTransformOriginPoint(QPoint(circle->x()+50,circle->y()+50));
    circle->setRotation(angle);
    radius->setRotation(angle);

}
