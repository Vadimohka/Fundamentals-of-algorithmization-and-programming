#include "wheel.h"

Wheel::Wheel()
{
    wheel = new QGraphicsEllipseItem(0,0,100,100,this);
    wheel->setPen(QPen(Qt::black,10,Qt::SolidLine));
    line = new QGraphicsLineItem(15,15,50,50,this);
    line->setPen(QPen(Qt::black,5,Qt::SolidLine));
}

void Wheel::rotateRight()
{
    rotationAngle+=15;
    wheel->setTransformOriginPoint(QPoint(wheel->x()+50,wheel->y()+50));
    line->setTransformOriginPoint(QPoint(wheel->x()+50,wheel->y()+50));
    wheel->setRotation(rotationAngle);
    line->setRotation(rotationAngle);
}

void Wheel::rotateLeft()
{
    rotationAngle-=15;
    wheel->setTransformOriginPoint(QPoint(wheel->x()+50,wheel->y()+50));
    line->setTransformOriginPoint(QPoint(wheel->x()+50,wheel->y()+50));
    wheel->setRotation(rotationAngle);
    line->setRotation(rotationAngle);
}
