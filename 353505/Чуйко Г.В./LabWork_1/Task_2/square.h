#ifndef SQUARE_H
#define SQUARE_H
#include "polygon.h"

class Square : public Polygon
{
public:
    Square();
    qreal HalfDiagonal;
};

#endif // SQUARE_H
