#include "shape.h"
void Shape::number_apexes(int number){}

void Shape::paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    QPolygonF polygon;
    QPointF rotationCenter;
    calculatePoints();
    rotationCenter = centerConnected ? QPointF(0 + X, 0 + Y) : QPointF(0 + rotateCenterX, 0 + rotateCenterY);
    painter->setRenderHint(QPainter::Antialiasing);
    move = {X,Y};
    painter->translate(rotationCenter);
    painter->rotate(rotateAngle);
    painter->translate(-rotationCenter);
    for(const auto &point : points){
        polygon << point * size + move;
    }
    painter->drawPolygon(polygon);
    painter->drawEllipse(rotationCenter,1,1);
}
void Shape::centerset(){
    centerX = 0;
    centerY = 0;
    int n = points.size();
    for(int i = 0;i < n;++i){
        centerX += pointsX[i] / n;
        centerY += pointsY[i] / n;
    }
    for(int i = 0;i < n;++i){
        points[i] -= {centerX,centerY};
    }

}
QRectF Shape::boundingRect() const{
    return QRectF();
}
void Shape::changesize(double spinsize){
    size = spinsize;
}
void Shape::changerad(double spinrad){
    radius = spinrad;
}
void Shape::moveX(double spinX){
    X = spinX;
}
void Shape::moveY(double spinY){
    Y = spinY;
}
void Shape::rotate(double spinangle){
    rotateAngle = spinangle;
}
void Shape::changerotateCenterX(double spincoordx){
    rotateCenterX = spincoordx;
}
void Shape::changerotateCenterY(double spincoordy){
    rotateCenterY = spincoordy;
}
qreal Shape::calculatePerimeter(){}
qreal Shape::calculateArea(){}
void Shape::calculatePoints(){}
