#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "myfigure.h"

class Ellipse : public MyFigure
{
public:
    Ellipse();
    auto Area() -> qreal override;
    auto Perimeter() -> qreal override;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * /*unused*/,
               QWidget * /*unused*/) override;
};

#endif // ELLIPSE_H
