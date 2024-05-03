#ifndef SQUARE_H
#define SQUARE_H
#include "rect.h"
class Square : public Rect
{
public:
    Square(QPointF p, qreal a);
    void SetStartParams();
    void findAreaSquare();
    qreal GetAreaSquare();
    void SetNewCoord(QPointF p, qreal a);
protected:
    qreal size = 0;
    qreal areaSquare = 0;
};

#endif // SQUARE_H
