#ifndef EIGHTPOINTEDSTAR_H
#define EIGHTPOINTEDSTAR_H

#include "myfigure.h"

class EightPointedStar : public MyFigure
{
public:
    EightPointedStar();
    auto Area() -> qreal override;
    auto Perimeter() -> qreal override;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * /*unused*/,
               QWidget * /*unused*/) override;
private:
    const int _multiplier = 8;
};

#endif // EIGHTPOINTEDSTAR_H
