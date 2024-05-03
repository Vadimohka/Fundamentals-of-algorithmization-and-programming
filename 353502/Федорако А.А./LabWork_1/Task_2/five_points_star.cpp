#include "five_points_star.h"

FivePointsStar::FivePointsStar(QPointF point) : Star(point)
{
    Star::setNumberStarPeaks(5);
}
