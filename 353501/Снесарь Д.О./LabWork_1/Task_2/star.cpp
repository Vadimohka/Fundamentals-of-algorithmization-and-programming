#include "star.h"


Star::Star(QPointF first, QPointF second, int n)
{
    center = first;
    sRad = second.x();
    bRad = second.y();
    int numOfPoints = n * 2;
    double alpha = 2.0 * M_PI/(2.0 * n);
    for (int i = 0; i < numOfPoints; ++i){
        if (i % 2 == 0){
            points.push_back(QPointF(center.x() + second.x() * cos(alpha * i),center.y() + second.x() * sin (alpha * i)));
        } else{
            points.push_back(QPointF(center.x() + second.y() * cos(alpha * i),center.y() + second.y() * sin (alpha * i)));
        }
    }
}

void Star::setSize(QPointF nPoint)
{

    int mCord = std::max(nPoint.x(), nPoint.y());
    double alpha = 2.0 * M_PI/(points.size());
    for (int i = 0; i < points.size(); ++i){
        if (i % 2 == 0){
            points[i] = (QPointF(center.x() + mCord * cos(alpha * i),center.y() + mCord * sin (alpha * i)));
        } else{
            points[i] = (QPointF(center.x() + mCord/2 * cos(alpha * i),center.y() + mCord/2 * sin (alpha * i)));
        }
    }
}
