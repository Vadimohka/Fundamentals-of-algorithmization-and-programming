#include "ffromb.h"

ffRomb::ffRomb()
{
    points.resize(4);
}

void ffRomb::setPoints(QPoint msBeg, QPoint msNow)
{
    massCenter = QPointF(msNow.rx() - (msNow.rx() - msBeg.rx())/2.0, msNow.ry() - (msNow.ry() - msBeg.ry())/2.0);

    float serx = msBeg.rx() + (msNow.rx() - msBeg.rx())/2.0;
    float sery = msBeg.ry() + (msNow.ry() - msBeg.ry())/2.0;

    points[0].rx() = serx;
    points[0].ry() = msBeg.ry();
    points[1].rx() = msNow.rx();
    points[1].ry() = sery;
    points[2].rx() = serx;
    points[2].ry() = msNow.ry();
    points[3].rx() = msBeg.rx();
    points[3].ry() = sery;
}
