#include "triangle.h"

Triangle::Triangle() {}

void Triangle::calculatePoints(){
    points.resize(3);
    pointsY.resize(3);
    pointsX.resize(3);
    pointsX[0] = 0;
    pointsY[0] = 0;
    pointsX[1] = side1;
    pointsY[1] = 0;
    pointsX[2] = (side3*side3 + side1*side1 - side2*side2) / (2.0 * side1);
    pointsY[2] = sqrt(side3*side3 - pow((side3*side3 + side1*side1 - side2*side2) / (2.0 * side1), 2));

    points[0] = QPointF(pointsX[0], pointsY[0]);
    points[1] = QPointF(pointsX[1], pointsY[1]);
    points[2] = QPointF(pointsX[2], pointsY[2]);
    centerset();
}


qreal Triangle::calculateArea(){
    double p = (side1 + side2 + side3) / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

qreal Triangle::calculatePerimeter(){
    return side1 + side2 + side3;
}

void Triangle::changeSide1(double spinside1){
    side1 = spinside1;
    calculatePoints();
}

void Triangle::changeSide2(double spinside2){
    side2 = spinside2;
    calculatePoints();
}

void Triangle::changeSide3(double spinside3){
    side3 = spinside3;
    calculatePoints();
}
