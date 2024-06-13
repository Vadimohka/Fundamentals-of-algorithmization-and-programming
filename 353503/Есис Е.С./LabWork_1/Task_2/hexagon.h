#ifndef HEXAGON_H
#define HEXAGON_H

#include "myfigure.h"

class Hexagon : public MyFigure
{
public:
    Hexagon();
    auto Area() -> qreal override;
    auto Perimeter() -> qreal override;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * /*unused*/,
               QWidget * /*unused*/) override;
private:
    const int _multiplier = 6;
};

#endif // HEXAGON_H
