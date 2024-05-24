#include "fftriangle.h"

ffTriangle::ffTriangle()
{
    points.resize(3);
}

void ffTriangle::setPoints(QPoint msBeg, QPoint msNow)
{
    massCenter = QPointF(msNow.rx() - (msNow.rx() - msBeg.rx())/2.0, msBeg.ry() + (msNow.ry() - msBeg.ry())/3.0);
    points[0] = msBeg;
    points[1].rx() = msNow.rx();
    points[1].ry() = msBeg.ry();
    points[2].rx() = msBeg.rx() + (msNow.rx() - msBeg.rx())/2.0;
    points[2].ry() = msNow.ry();
}
