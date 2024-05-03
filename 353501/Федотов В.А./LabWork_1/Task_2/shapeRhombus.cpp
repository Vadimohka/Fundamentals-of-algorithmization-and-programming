#include "shapeRhombus.h"

ShapeRhombus::ShapeRhombus()
{
    side1 = 200;
    anglePoly = 90;

    h1 = side1 * qCos(qDegreesToRadians(anglePoly/2));
    h2 = side1 * qSin(qDegreesToRadians(anglePoly/2));

    pointsX.append(0);
    pointsY.append(0);
    pointsX.append(h1);
    pointsY.append(-h2);
    pointsX.append(2 * h1);
    pointsY.append(0);
    pointsX.append(h1);
    pointsY.append(h2);

    points.append(QPointF(pointsX[0], pointsY[0]));
    points.append(QPointF(pointsX[1], pointsY[1]));
    points.append(QPointF(pointsX[2], pointsY[2]));
    points.append(QPointF(pointsX[3], pointsY[3]));
}

void ShapeRhombus::calculatePoints()
{
    h1 = side1 * qCos(qDegreesToRadians(anglePoly/2));
    h2 = side1 * qSin(qDegreesToRadians(anglePoly/2));

    pointsX[0] = (0);
    pointsY[0] = (0);
    pointsX[1] = (h1);
    pointsY[1] = (-h2);
    pointsX[2] = (2 * h1);
    pointsY[2] = (0);
    pointsX[3] = (h1);
    pointsY[3] = (h2);

    points[0] = (QPointF(pointsX[0], pointsY[0]));
    points[1] = (QPointF(pointsX[1], pointsY[1]));
    points[2] = (QPointF(pointsX[2], pointsY[2]));
    points[3] = (QPointF(pointsX[3], pointsY[3]));

    setCenterOfMass();
}

void ShapeRhombus::clear()
{
    anglePoly = 90;

    shiftX = 0;
    shiftY = 0;
    rotation = 0;

    lastShiftX = 0;
    lastShiftY = 0;

    scale = 1;

    detached = false;
}


