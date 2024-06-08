#ifndef STRAIGHTLINEPATH_H
#define STRAIGHTLINEPATH_H

#include "path.h"
#include "QPointF"

class StraightLinePath : public Path
{
public:

    StraightLinePath(const QPointF& start, const QPointF& end, int points = 1);
    virtual QPointF PointAt(float p) const override;
    virtual int Size() const override;

private:
    QPointF startPoint;
    QPointF endPoint;
    int numPoints;

};

#endif // STRAIGHTLINEPATH_H
