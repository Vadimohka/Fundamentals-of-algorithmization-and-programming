#ifndef CIRCLE_H
#define CIRCLE_H

#include "myfigure.h"

class Circle : public MyFigure
{
public:
    Circle();
    auto Area() -> qreal override;
    auto Perimeter() -> qreal override;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * /*unused*/,
               QWidget * /*unused*/) override;
};

#endif // CIRCLE_H
