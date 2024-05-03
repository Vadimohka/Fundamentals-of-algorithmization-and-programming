#include "triangle.h"

void Triangle::setP(QMouseEvent *now) {
    if(points.size()==3)

    {
        points.clear();

    }
    points.push_back(now->pos());
    S=0;
    P=0;
    if(points.size()==3)
    {
        center={(points[0]+points[1]+points[2])/3};
        findSquare();
        findPerimetr();
    }

}
