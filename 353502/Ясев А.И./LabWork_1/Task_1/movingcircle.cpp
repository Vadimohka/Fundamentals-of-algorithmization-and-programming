#include "movingcircle.h"

MovingCircle::MovingCircle(QGraphicsScene *parent) :
    QObject(parent), QGraphicsItem()
{
    center.setX(parent->width()/2);
    center.setY(parent->height()/2);
    this->setPos(center);
    this->setTransformOriginPoint(center);
    step = parent->width()/10;
}

MovingCircle::~MovingCircle(){

}

QRectF MovingCircle::boundingRect() const
{
    return QRectF(-150,-150,300,300);
}

void MovingCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(isrotated){
        painter->rotate(45);
    }
    painter->setPen(QPen(QColor(0,0,0)));
    painter->setBrush(QBrush(QColor(138,46,225,0)));
    painter->drawEllipse(-150,-150,300,300);
}

void MovingCircle::moveLeft(){
    center.setX(center.x()-step);
    this->setPos(center);
    this->setTransformOriginPoint(center);
    isrotated = !isrotated;
    update();
}

void MovingCircle::moveRight(){
    center.setX(center.x()+step);
    this->setPos(center);
    this->setTransformOriginPoint(center);
    isrotated = !isrotated;
    update();
}

