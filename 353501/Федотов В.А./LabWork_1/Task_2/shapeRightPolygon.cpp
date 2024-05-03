#include "shapeRightPolygon.h"

ShapeRightPolygon::ShapeRightPolygon()
{
    int polygonPoints = numPoints;

    double angleIncrement = 2 * M_PI / polygonPoints;
    double angleOffset = -M_PI / 2;

    for (int i = 0; i < polygonPoints; ++i)
    {
        double angle = i * angleIncrement + angleOffset;
        pointsX.append( center.x() + radius1 * cos(angle));
        pointsY.append(center.y() + radius1 * sin(angle));
        points.append(QPointF(pointsX[i], pointsY[i]));
    }
}

void ShapeRightPolygon::calculatePoints()
{
    int polygonPoints = numPoints;

    double angleIncrement = 2 * M_PI / polygonPoints;
    double angleOffset = -M_PI / 2;

    pointsX.resize(polygonPoints);
    pointsY.resize(polygonPoints);
    points.resize(polygonPoints);

    for (int i = 0; i < polygonPoints; ++i)
    {
        double angle = i * angleIncrement + angleOffset;
        pointsX[i] = center.x() + radius1 * cos(angle);
        pointsY[i] = center.y() + radius1 * sin(angle);
        points[i] = QPointF(pointsX[i], pointsY[i]);
    }

    setCenterOfMass();
}

void ShapeRightPolygon::clear()
{
    numPoints = 5;

    shiftX = 0;
    shiftY = 0;
    rotation = 0;

    lastShiftX = 0;
    lastShiftY = 0;

    scale = 1;

    detached = false;


}
