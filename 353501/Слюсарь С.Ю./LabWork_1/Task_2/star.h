#ifndef STAR_H
#define STAR_H

#include "figure.h"
class Star : public Figure
{
public:
    Star();
    double distance(QPointF p1, QPointF p2);

protected:
    int x_;
    int y_;
    int radius_;
    QPointF p[9];
};

#endif // STAR_H
