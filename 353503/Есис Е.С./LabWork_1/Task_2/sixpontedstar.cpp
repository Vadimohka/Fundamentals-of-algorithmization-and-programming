#include "sixpontedstar.h"
constexpr double M_PI = 3.14;
#include <QtMath>

SixPontedStar::SixPontedStar() = default;

auto SixPontedStar::Area() -> qreal
{
    return this -> getScale() * this -> getScale() * (M_PI * radius1 * radius1 + (M_PI * radius2 * radius2 - M_PI * radius1 * radius1) / 5);
}

auto SixPontedStar::Perimeter() -> qreal
{
    return this -> getScale() * _multiplier * (radius1 + radius2);
}

void SixPontedStar::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem * /*unused*/,
                          QWidget * /*unused*/)
{
    painter -> setRenderHint(QPainter::Antialiasing, true);

    QPointF starPoints[2 * _multiplier + 1];

    for(int i = 0; i < _multiplier; ++i)
    {
        starPoints[i * 2] = QPointF(static_cast<qreal>(-radius1 * sin(2 * M_PI / _multiplier * i)),
                                    static_cast<qreal>(-radius1 * cos(2 * M_PI / _multiplier * i)));
        starPoints[i * 2 + 1] = QPointF(static_cast<qreal>(-radius2 / 2
                                                           * sin(2 * M_PI / _multiplier * i + M_PI / _multiplier)),
                                        static_cast<qreal>(-radius2 / 2
                                                           * cos(2 * M_PI / _multiplier * i + M_PI / _multiplier)));
    }
    starPoints[2 * _multiplier].rx() = starPoints[0].rx();
    starPoints[2 * _multiplier].ry() = starPoints[0].ry();

    for(int i = 0; i < 2 * _multiplier; ++i)
    {
        painter -> drawLine(starPoints[i].rx(), starPoints[i].ry(), starPoints[i + 1].rx(), starPoints[i + 1].ry());
    }
}

