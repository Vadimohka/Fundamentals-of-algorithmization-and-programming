#ifndef RECT_H
#define RECT_H
#include "parallelogram.h"
class Rect : public Parallelogram
{
public:
    Rect();
    Rect(QPointF p, qreal a, qreal b);
    void SetStartParams();
    void findSquareRect();
    qreal GetSquareRect();
    void SetNewCoord(QPointF p, qreal a, qreal b);
protected:
    qreal length = 0;
    qreal width = 0;
    qreal squareRect = 0;
};

#endif // RECT_H
