#include "ffrect.h"

ffRect::ffRect()
{
    points.resize(4);
}

void ffRect::setPoints(QPoint msBeg, QPoint msNow)
{
    massCenter = QPointF(msNow.rx() - (msNow.rx() - msBeg.rx())/2.0, msNow.ry() - (msNow.ry() - msBeg.ry())/2.0);
    points[0] = msBeg;
    points[1].rx() = msNow.rx();
    points[1].ry() = msBeg.ry();
    points[2] = msNow;
    points[3].rx() = msBeg.rx();
    points[3].ry() = msNow.ry();
}
