#include "hexagon.h"
constexpr double M_PI = 3.14;

#include <QtMath>
Hexagon::Hexagon() = default;

auto Hexagon::Area() -> qreal
{
    return this -> getScale() * this -> getScale() * 3 * radius * radius * sqrt(3) / 2;
}

auto Hexagon::Perimeter() -> qreal
{
    return this -> getScale() * _multiplier * radius;
}

void Hexagon::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem * /*unused*/,
                    QWidget * /*unused*/)
{
    painter -> setRenderHint(QPainter::Antialiasing, true);
    QPolygon hexagonPolygon;
    hexagonPolygon << QPoint(-radius, 0)
                   << QPoint(-radius / 2, radius * sqrt(3) / 2)
                   << QPoint(radius / 2, radius * sqrt(3) / 2)
                   << QPoint(radius, 0)
                   << QPoint(radius / 2, -radius * sqrt(3) / 2)
                   << QPoint(-radius / 2, -radius * sqrt(3) / 2);
    painter -> drawPolygon(hexagonPolygon);
}
