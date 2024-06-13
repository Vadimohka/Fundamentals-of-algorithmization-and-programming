#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "myfigure.h"

class Rectangle : public MyFigure
{
public:
    Rectangle();
    auto Area() -> qreal override;
    auto Perimeter() -> qreal override;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * /*unused*/,
               QWidget * /*unused*/) override;
};

#endif // RECTANGLE_H
