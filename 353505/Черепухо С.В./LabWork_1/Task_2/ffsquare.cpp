#include "ffsquare.h"

ffSquare::ffSquare()
{
    points.resize(4);
}

void ffSquare::setPoints(QPoint msBeg, QPoint msNow)
{
    msNow.ry() = msBeg.ry() + (msNow.rx() - msBeg.rx());
    massCenter = QPointF(msNow.rx() - (msNow.rx() - msBeg.rx())/2.0, msNow.ry() - (msNow.ry() - msBeg.ry())/2.0);
    points[0] = msBeg;
    points[1].rx() = msNow.rx();
    points[1].ry() = msBeg.ry();
    points[2] = msNow;
    points[3].rx() = msBeg.rx();
    points[3].ry() = msNow.ry();
}
