#ifndef EIGHT_POINTS_STAR_H
#define EIGHT_POINTS_STAR_H

#include "star.h"

class EightPointsStar : public Star
{
public:
    explicit EightPointsStar(QPointF point);
private:
    int const numberStarPeaks = 8;
};

#endif // EIGHT_POINTS_STAR_H
