#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <myfigure.h>

class Triangle : public MyFigure
{
public:
    Triangle();
    auto Area() -> qreal override;
    auto Perimeter() -> qreal override;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * /*unused*/,
               QWidget * /*unused*/) override;
};

#endif // TRIANGLE_H
