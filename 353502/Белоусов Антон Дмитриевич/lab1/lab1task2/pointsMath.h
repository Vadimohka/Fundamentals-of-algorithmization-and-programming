#ifndef POINTSMATH_H
#define POINTSMATH_H

#include <QtCore>
#include <cmath>
#include <iostream>

const int HALF_OF_CIRCLE_IN_DEGREES = 180;

double distance(QPointF first_point, QPointF second_point);

double distanceToLine(QPointF point, QPointF first_point, QPointF second_point);

bool isHorizontalRightRayIntersectingSegment(QPointF startOfTheRay, QPointF first_point, QPointF second_point);

#endif // POINTSMATH_H
