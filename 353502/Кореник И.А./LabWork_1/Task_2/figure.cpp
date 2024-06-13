#include "figure.h"

Figure::Figure(QWidget *parent)
    : QWidget{parent}
{
    this->setParent(parent);
}


void Figure::setPoints() {

}


void Figure::draw(QPainter* dp){
    pol.clear();
    for (auto p : points) {
        pol << p;
    }
    dp->drawPolygon(pol);
}


void Figure::move(){
    QPoint dif = mouseNow - mousePress;
    for (auto &point: points) {
        point += dif;
    }
    centre += dif;
    mousePress = mouseNow;
}


void Figure::mousePressing(QMouseEvent *evt){
    mousePress = evt->pos();
    mouseNow = evt->pos();
    //setPoints(evt);
}


void Figure::mouseMoving(QMouseEvent *evt){
    mouseNow = evt->pos();
    setPoints();
    setInfo();
}


void Figure::mousePressingMoveMode(QMouseEvent *evt){
    mousePress = evt->pos();
}


void Figure::mouseMovingMoveMode(QMouseEvent *evt){
    mouseNow = evt->pos();
    move();
}


void Figure::calcArea(){

}


void Figure::calcCentre(){

}


void Figure::calcPerimetr(){

}


void Figure::setInfo(){
    calcArea();
    calcCentre();
    calcPerimetr();
}


float Figure::getArea(){
    return area;
}


float Figure::getPerimetr(){
    return perimetr;
}


QPointF Figure::getCentre(){
    return centre;
}


void Figure::rotateRight(){
    for (auto& p : points){
        double newX = centre.x() + qCos(-angle) * (p.x() - centre.x()) - qSin(-angle) * (p.y() - centre.y());
        double newY = centre.y() + qSin(-angle) * (p.x() - centre.x()) + qCos(-angle) * (p.y() - centre.y());
        p = {newX, newY};
    }
    update();
}


void Figure::rotateLeft(){
    for (auto& p : points){
        double newX = centre.x() + qCos(angle) * (p.x() - centre.x()) - qSin(angle) * (p.y() - centre.y());
        double newY = centre.y() + qSin(angle) * (p.x() - centre.x()) + qCos(angle) * (p.y() - centre.y());
        p = {newX, newY};
    }
    update();
}


void Figure::rotate(float angle){
    for (auto& p : points){
        double newX = centre.x() + qCos(angle) * (p.x() - centre.x()) - qSin(angle) * (p.y() - centre.y());
        double newY = centre.y() + qSin(angle) * (p.x() - centre.x()) + qCos(angle) * (p.y() - centre.y());
        p = {newX, newY};
    }
    update();
}


void Figure::increase(){
    for (auto& point : points){
        QPointF dif = point - centre;
        point += dif * resizeConst;
        this->setInfo();
    }
}

void Figure::decrease(){
    for (auto& point : points){
        QPointF dif = point - centre;
        point -= dif * resizeConst;
        this->setInfo();
    }
}


bool Figure::isInside(QMouseEvent*){
    return false;
}


void Figure::setN(QString){

}
