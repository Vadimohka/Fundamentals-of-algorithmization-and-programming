#include "ffnanglyy.h"

ffNanglyy::ffNanglyy(int n)
{
    if(n > 2)
        points.resize(n);
}

void ffNanglyy::setPoints(QPoint msBeg, QPoint msNow)
{
    massCenter = msBeg;
    float radius = abs(msNow.rx() - msBeg.rx());

    float plus = PI/2;

    for(int i = 0; i < points.size(); i++)
    {
        points[i].rx() = massCenter.rx() + radius*cos(2*PI/points.size() * i - plus);
        points[i].ry() = massCenter.ry() + radius*sin(2*PI/points.size() * i - plus);
    }
}


