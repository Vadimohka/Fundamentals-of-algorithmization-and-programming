#include "Daughter_shape.h"

constexpr int FIRST_POINT_OFFSET = 50;
constexpr int X_OFFSET = 190;
constexpr int Y_OFFSET = 400;
constexpr int X_2_COORD = 200;

QPolygonF DaughterShape::paint()
{
    polygon.clear();
    mainPoint = getX() + FIRST_POINT_OFFSET;
    point_x = mainPoint + X_OFFSET;
    polygon << QPoint(mainPoint, Y_OFFSET) << QPoint(point_x, Y_OFFSET) << QPoint(point_x, X_2_COORD);
    return polygon;
}
