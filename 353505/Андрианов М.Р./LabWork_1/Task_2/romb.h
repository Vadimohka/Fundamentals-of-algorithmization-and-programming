#ifndef ROMB_H
#define ROMB_H

#include "polygon.h"

class Romb : public Polygon
{
public:
    Romb();
protected:
    qreal Diagonal1Len;
    qreal Diagonal2Len;
};

#endif // ROMB_H
