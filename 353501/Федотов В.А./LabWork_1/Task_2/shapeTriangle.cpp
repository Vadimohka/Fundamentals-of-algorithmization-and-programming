#include "shapeTriangle.h"
#include <QDebug>

ShapeTriangle::ShapeTriangle()
{
    side1 = 200;
    side2 = 200;
    side3 = 200;

    pointsX.append(0);
    pointsY.append(0);
    pointsX.append(side1);
    pointsY.append(0);
    pointsX.append((side3*side3 + side1*side1 - side2*side2) / (2.0 * side1));
    pointsY.append(sqrt(side3*side3 - pow((side3*side3 + side1*side1 - side2*side2) / (2.0 * side1), 2)));

    points.append(QPointF(pointsX[0], pointsY[0]));
    points.append(QPointF(pointsX[1], pointsY[1]));
    points.append(QPointF(pointsX[2], pointsY[2]));
}

void ShapeTriangle::calculatePoints()
{
    pointsX[0] = 0;
    pointsY[0] = 0;
    pointsX[1] = side1;
    pointsY[1] = 0;
    pointsX[2] = (side3*side3 + side1*side1 - side2*side2) / (2.0 * side1);
    pointsY[2] = sqrt(side3*side3 - pow((side3*side3 + side1*side1 - side2*side2) / (2.0 * side1), 2));

    points[0] = QPointF(pointsX[0], pointsY[0]);
    points[1] = QPointF(pointsX[1], pointsY[1]);
    points[2] = QPointF(pointsX[2], pointsY[2]);

    setCenterOfMass();
}

void ShapeTriangle::clear()
{
    side1 = 200;
    side2 = 200;
    side3 = 200;

    shiftX = 0;
    shiftY = 0;
    rotation = 0;

    lastShiftX = 0;
    lastShiftY = 0;

    scale = 1;

    detached = false;
}



