#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "parallelogram.h"
class Rhombus : public Parallelogram
{
public:
    Rhombus(QPointF p, qreal a);
    void SetNewCoord(QPointF p, qreal a);
    void SetStartParams();
    void findSquareRomb();
    qreal GetSquareRomb();
protected:
    qreal squareRomb = 0;
    qreal size = 0;
};

#endif // RHOMBUS_H
