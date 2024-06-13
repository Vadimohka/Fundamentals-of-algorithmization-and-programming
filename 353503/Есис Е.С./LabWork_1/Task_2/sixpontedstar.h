#ifndef SIXPONTEDSTAR_H
#define SIXPONTEDSTAR_H

#include "myfigure.h"

class SixPontedStar : public MyFigure
{
public:
    SixPontedStar();
    auto Area() -> qreal override;
    auto Perimeter() -> qreal override;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * /*unused*/,
               QWidget * /*unused*/) override;
private:
    const int _multiplier = 6;
};

#endif // SIXPONTEDSTAR_H
