#include "triangle.h"
constexpr double M_PI = 3.14;
#include <QtMath>

Triangle::Triangle() = default;

auto Triangle::Area() -> qreal
{
    return this -> getScale() * this -> getScale() * size * size * sqrt(3) / 4;
}

auto Triangle::Perimeter() -> qreal
{
    return this -> getScale() * 3 * size;
}

void Triangle::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem * /*unused*/,
                     QWidget * /*unused*/)
{
    painter -> setRenderHint(QPainter::Antialiasing, true);

    QPolygon trianglePolygon;
    trianglePolygon << QPoint(-size * sqrt(3), size * sqrt(3))
                    << QPoint(0, -size * sqrt(3))
                    << QPoint(size * sqrt(3), size * sqrt(3));
    painter -> drawPolygon(trianglePolygon);
}
