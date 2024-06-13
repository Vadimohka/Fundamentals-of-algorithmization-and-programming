#ifndef FIVEPOINTEDSTAR_H
#define FIVEPOINTEDSTAR_H

#include "myfigure.h"

class FivePointedStar : public MyFigure
{
public:
    FivePointedStar();
    auto Area() -> qreal override;
    auto Perimeter() -> qreal override;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * /*unused*/,
               QWidget * /*unused*/) override;
private:
    const int _multiplier = 5;
};

#endif // FIVEPOINTEDSTAR_H
