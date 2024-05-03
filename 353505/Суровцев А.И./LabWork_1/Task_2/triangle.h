#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "par_polygon.h"
class Triangle : public par_polygon
{
public:
    Triangle(QPointF p1, QPointF p2, QPointF p3);
    void SetStartParams();
    bool isTriangle(const QPointF& p1, const QPointF& p2, const QPointF& p3);
    void findSquareTriangle();
    qreal GetSquareTriangle();
    void SetNewCoord(QPointF p1, QPointF p2, QPointF p3);
private:
    QPointF start_p1;
    QPointF start_p2;
    QPointF start_p3;
    qreal squareTR = 0;
};

#endif // TRIANGLE_H
