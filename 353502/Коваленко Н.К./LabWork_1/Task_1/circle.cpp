#include "circle.h"

Circle::Circle(QGraphicsScene *parent) :
    QObject(parent), QGraphicsItem()
{
    center.setX(parent->width()/2);
    center.setY(parent->height()/2);
    this->setPos(center);
    this->setTransformOriginPoint(center);
    step = parent->width()/15;
}

Circle::~Circle(){

}

QRectF Circle::boundingRect() const
{
    return QRectF(-150,-150,300,300);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(isrotated){
        painter->rotate(45);
    }
    painter->setPen(QPen(QColor(0,0,0)));
    painter->setBrush(QBrush(QColor(138,46,225,0)));
    painter->drawEllipse(-150,-150,300,300);
}

void Circle::moveLeft(){
    center.setX(center.x()-step);
    this->setPos(center);
    this->setTransformOriginPoint(center);
    isrotated = !isrotated;
    update();
}

void Circle::moveRight(){
    center.setX(center.x()+step);
    this->setPos(center);
    this->setTransformOriginPoint(center);
    isrotated = !isrotated;
    update();
}

void Circle::moveCenter(){
    center.setX(661);
    this->setPos(center);
    this->setTransformOriginPoint(center);
    isrotated = !isrotated;
    update();
}
