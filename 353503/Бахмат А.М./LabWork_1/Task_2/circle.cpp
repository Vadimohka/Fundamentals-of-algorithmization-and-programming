#include "circle.h"

Circle::Circle() = default;

auto Circle::Area() -> qreal
{
    return this -> getScale() * this -> getScale() * M_PI * radius * radius;
}

auto Circle::Perimeter() -> qreal
{
    return this -> getScale() * 2 * M_PI * radius;
}

void Circle::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem * /*unused*/,
                   QWidget * /*unused*/)
{
    painter -> setRenderHint(QPainter::Antialiasing, true);
    painter -> drawEllipse(-radius / 2, -radius / 2, radius, radius);
}
