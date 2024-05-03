#include "shapeSquare.h"

ShapeSquare::ShapeSquare()
{
    side1 = 200;

    pointsX = {0, 0,        side1,  side1};
    pointsY = {0, side1,    side1,  0};

    points.append(QPointF(pointsX[0], pointsY[0]));
    points.append(QPointF(pointsX[1], pointsY[1]));
    points.append(QPointF(pointsX[2], pointsY[2]));
    points.append(QPointF(pointsX[3], pointsY[3]));
}


void ShapeSquare::calculatePoints()
{
    pointsX[0] = 0;
    pointsX[1] = 0;
    pointsX[2] = side1;
    pointsX[3] = side1;

    pointsY[0] = 0;
    pointsY[1] = side1;
    pointsY[2] = side1;
    pointsY[3] = 0;

    points[0] = QPointF(pointsX[0], pointsY[0]);
    points[1] = QPointF(pointsX[1], pointsY[1]);
    points[2] = QPointF(pointsX[2], pointsY[2]);
    points[3] = QPointF(pointsX[3], pointsY[3]);

    setCenterOfMass();
}

void ShapeSquare::clear()
{
    side1 = 200;

    shiftX = 0;
    shiftY = 0;
    rotation = 0;

    lastShiftX = 0;
    lastShiftY = 0;

    scale = 1;

    detached = false;
}




