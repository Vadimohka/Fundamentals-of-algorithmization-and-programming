#include "six_points_star.h"

SixPointsStar::SixPointsStar(QPointF point) : Star(point)
{
    Star::setNumberStarPeaks(6);
}
