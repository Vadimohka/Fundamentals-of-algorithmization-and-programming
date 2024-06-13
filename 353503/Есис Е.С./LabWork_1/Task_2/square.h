#ifndef SQUARE_H
#define SQUARE_H

#include "myfigure.h"

class Square : public MyFigure
{
public:
    Square();
    auto Area() -> qreal override;
    auto Perimeter() -> qreal override;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * /*unused*/,
               QWidget * /*unused*/) override;
};

#endif // SQUARE_H
