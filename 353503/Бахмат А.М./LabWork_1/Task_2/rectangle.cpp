#include "rectangle.h"

Rectangle::Rectangle() = default;

auto Rectangle::Area() -> qreal
{
    return this -> getScale() * this -> getScale() * height * width;
}

auto Rectangle::Perimeter() -> qreal
{
    return this -> getScale() * 2 * (height + width);
}

void Rectangle::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem * /*unused*/,
                      QWidget * /*unused*/)
{
    painter -> setRenderHint(QPainter::Antialiasing, true);
    painter -> drawRect(-height / 2, -width / 2, height, width);
}
