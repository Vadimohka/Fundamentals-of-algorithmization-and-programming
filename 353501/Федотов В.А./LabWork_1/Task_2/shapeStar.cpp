#include "shapeStar.h"

ShapeStar::ShapeStar()
{
    points.clear();

    int starPoints = numPoints * 2;

    double angleIncrement = 2 * M_PI / starPoints;
    double angleOffset = M_PI / 2;

    for (int i = 0; i < starPoints; i += 2)
    {
        double outerAngle = i * angleIncrement + angleOffset;

        pointsX.push_back(radius2 * cos(outerAngle));
        pointsY.push_back(radius2 * sin(outerAngle));
        points.push_back(QPointF(pointsX[i], pointsY[i]));

        double innerAngle = (i + 1) * angleIncrement + angleOffset;

        pointsX.push_back(radius1 * cos(innerAngle));
        pointsY.push_back(radius1 * sin(innerAngle));
        points.push_back(QPointF(pointsX[i+1], pointsY[i+1]));
    }

    setCenterOfMass();
}

void ShapeStar::calculatePoints()
{

    int starPoints = numPoints * 2;

    double angleIncrement = 2 * M_PI / starPoints;
    double angleOffset = M_PI / 2;

    pointsX.resize(starPoints);
    pointsY.resize(starPoints);
    points.resize(starPoints);

    for (int i = 0; i < starPoints; i += 2)
    {
        double outerAngle = i * angleIncrement + angleOffset;

        pointsX[i] = radius2 * cos(outerAngle);
        pointsY[i] = radius2 * sin(outerAngle);
        points[i] = QPointF(pointsX[i], pointsY[i]);

        double innerAngle = (i + 1) * angleIncrement + angleOffset;

        pointsX[i+1] = radius1 * cos(innerAngle);
        pointsY[i+1] = radius1 * sin(innerAngle);
        points[i+1] = QPointF(pointsX[i+1], pointsY[i+1]);
    }

    setCenterOfMass();
}

void ShapeStar::clear()
{
    radius1 = 100;
    radius2 = 50;

    shiftX = 0;
    shiftY = 0;
    rotation = 0;

    lastShiftX = 0;
    lastShiftY = 0;

    scale = 1;

    detached = false;
}
