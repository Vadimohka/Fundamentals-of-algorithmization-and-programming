#include "ellipse.h"
#include <QtMath>

//constexpr double M_PI = 3.14;

Ellipse::Ellipse() = default;

auto Ellipse::Area() -> qreal
{
    return this -> getScale() * this -> getScale() * M_PI * radius * radius / 2;
}

auto Ellipse::Perimeter() -> qreal
{
    return this -> getScale() * (M_PI * radius * radius / 2 + radius / 2) / (radius * 3 / 2) * 4;
}

void Ellipse::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem * /*unused*/,
                    QWidget * /*unused*/)
{
    painter -> setRenderHint(QPainter::Antialiasing, true);
    painter -> drawEllipse(-radius / 2 - radius / 4, -radius / 2 , radius + radius / 2, radius);
}
