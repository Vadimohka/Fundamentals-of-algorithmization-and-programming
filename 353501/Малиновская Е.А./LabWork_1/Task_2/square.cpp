#include "square.h"

Square::Square() {}

void Square::calculatePoints() {
    points.resize(4);
    pointsX.resize(4);
    pointsY.resize(4);

    pointsX[0] = 0;
    pointsY[0] = 0;

    pointsX[1] = side;
    pointsY[1] = 0;

    pointsX[2] = side;
    pointsY[2] = side;

    pointsX[3] = 0;
    pointsY[3] = side;

    for (int i = 0; i < 4; ++i) {
        points[i] = QPointF(pointsX[i], pointsY[i]);
    }
    centerset();
}

qreal Square::calculateArea(){
    return side * side;
}

qreal Square::calculatePerimeter(){
    return side * 4;
}

void Square::changeSide(double spinside){
    side = spinside;
    calculatePoints();
}
