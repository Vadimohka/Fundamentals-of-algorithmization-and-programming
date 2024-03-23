#include "triangle.h"
#include <cmath>

Triangle::Triangle(){

    side1 = valueA;
    side2 = valueB;
    side3 = valueC;

    pointsX.append(0);
    pointsY.append(0);
    pointsX.append(side1);
    pointsY.append(0);
    pointsX.append((side3 * side3 + side1 * side1 - side2 * side2) / (2.0 * side1));
    pointsY.append(sqrt(side3 * side3 - pow((side3 * side3 + side1 * side1 - side2 * side2) / (2.0 * side1), 2)));

    for(int i = 0; i < 3; i++){
        points.append(QPointF(pointsX[i], pointsY[i]));
    }
}

void Triangle::calculatePoints(){
    points.resize(3);
    side1 = valueA;
    side2 = valueB;
    side3 = valueC;

    pointsX[0] = 0;
    pointsY[0] = 0;
    pointsX[1] = side1;
    pointsY[1] = 0;
    pointsX[2] = (side3 * side3 + side1 * side1 - side2 * side2) / (2.0 * side1);
    pointsY[2] = sqrt(side3 * side3 - pow((side3 * side3 + side1 * side1 - side2 * side2) / (2.0 * side1), 2));

    centerX = 0;
    centerY = 0;

    for(int i = 0 ; i < 3; i++){
        centerX += pointsX[i] / 3.0;
        centerY += pointsY[i] / 3.0;
    }

    for(int i = 0; i < 3; i ++){
        pointsX[i] -= centerX;
        pointsY[i] -= centerY;
        points[i] = QPointF(pointsX[i], pointsY[i]);
    }
}

void Triangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);

    calculatePoints();

    center = {moveX, moveY};
    move = QPointF(moveX, moveY);
    disconnectedMove = QPointF(disconnectedMoveX, disconnectedMoveY);

    QPolygonF triangle;
    if(!wasCenterDisconnected){
        for(int i = 0; i < 3; i++){
            triangle << points[i] * scale + move;
        }
    }
    else{
        for(int i = 0; i < 3; i++){
            triangle << points[i]  * scale + disconnectedMove;
        }
    }

    painter->translate(center);
    painter->rotate(angle);
    painter->translate(-center);

    painter->setBrush(Qt::red);
    painter->drawPolygon(triangle);
    painter->setBrush(Qt::white);
    painter->drawEllipse(center, 2, 2);
}


void Triangle::setValueC(double value){
    if(value < valueA + valueB){
        valueC = value;
    }
}

void Triangle::setValueA(double value){
    if(value < valueB + valueC){
        valueA = value;
    }
}

void Triangle::setValueB(double value){
    if(value < valueA + valueC){
        valueB = value;
    }
}
