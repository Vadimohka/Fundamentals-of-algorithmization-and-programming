#include "ellipse.h"


Ellipse::Ellipse(Widget *parent)
    : Widget{}
{
    this->setParent(parent);
}



void Ellipse::setSpeed(int speed){
    this->speed = speed;
}

void Ellipse::paintEvent(QPaintEvent *event){
    QPainter* painter = new QPainter;
    painter->begin(this);

    QPen pen(Qt::green);
    pen.setWidth(5);

    painter->setPen(pen);

    painter->drawEllipse(140, 170, 80, 100);

    painter->end();
}

void Ellipse::moveLeft(){

    if (this->x() >= -75)
        this->move(this->x() - speed,this->y());
}

void Ellipse::moveRight(){
    if (this->x() <= 565)
        this->move(this->x() + speed,this->y());
}

void Ellipse::moveUp(){
    if (this->y() >= -50)
        this->move(this->x(),this->y() - speed);
}

void Ellipse::moveDown(){
    if (this->y() <= 300)
        this->move(this->x(),this->y() + speed);
}

void Ellipse::remove(){
    this->hide();
}
