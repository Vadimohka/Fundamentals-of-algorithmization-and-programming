#include "circle.h"


Circle::Circle(QWidget *parent)
    : Figure(parent)
{
    this->setParent(parent);

    points.clear();

}


void Circle::mousePressing(QMouseEvent *evt){
    mousePress = evt->pos();
    centre = mousePress;
}


void Circle::mouseMoving(QMouseEvent *evt){
    mouseNow = evt->pos();

    float rX = mouseNow.x() - mousePress.x();
    float rY = mouseNow.y() - mousePress.y();
    r = sqrt(rX * rX + rY * rY);

}


void Circle::move(){
    QPoint dif = mouseNow - mousePress;
    centre += dif;
    mousePress = mouseNow;
}


void Circle::draw(QPainter *painter){

    painter->drawEllipse(centre, r, r);

}


void Circle::calcArea(){
    area = M_PI * r * r;
}

void Circle::calcPerimetr(){
    perimetr = M_PI * r * 2;
}

void Circle::calcCentre(){

}


void Circle::decrease(){
    r *= (1 - resizeConst);
    calcArea();
    calcPerimetr();
    update();
}


void Circle::increase(){
    r*= (1 + resizeConst);
    calcArea();
    calcPerimetr();
    update();
}


bool Circle::isInside(QMouseEvent *evt){
    QPointF dist = evt->pos() - centre;
    if (pow(dist.x(), 2) + pow(dist.y(), 2) <= r * r)
        return true;
    else
        return false;
}
