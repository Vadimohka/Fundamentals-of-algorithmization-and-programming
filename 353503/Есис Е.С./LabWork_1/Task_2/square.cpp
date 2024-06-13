#include "square.h"
constexpr double M_PI = 3.14;
#include <QtMath>

Square::Square() = default;

auto Square::Area() -> qreal
{
    return this -> getScale() * this -> getScale() * size * size;
}

auto Square::Perimeter() -> qreal
{
    return this -> getScale() * 4 * size;
}

void Square::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem * /*unused*/,
                   QWidget * /*unused*/)
{
    painter -> setRenderHint(QPainter::Antialiasing, true);
    painter -> drawRect(-size / 2, -size / 2, size, size);
}
