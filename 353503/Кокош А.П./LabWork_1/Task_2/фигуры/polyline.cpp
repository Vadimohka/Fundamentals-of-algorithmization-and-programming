#include "polyline.h"

void polyline::setPoints(QMouseEvent *me)
{
    mouseCurrentPos = me->pos();
    points.push_back(mouseCurrentPos);
}

void polyline::draw(QPainter *p)
{
    for (int i = 0; i < points.size() - 1; i++) {
        p->drawLine(points[i], points[i + 1]);
    }
}

void polyline::findSquare() {
    findPerimetr();
    square = (perimetr - 2) / 2;
}

void polyline::findPerimetr() {
    perimetr = 0;
    if (points.size() > 2) {
        for (int i = 0; i < points.size() - 1; i++) {
            perimetr += qSqrt(
                (points[i].y() - points[i + 1].y()) * (points[i].y() - points[i + 1].y())
                + (points[i].x() - points[i + 1].x()) * (points[i].x() - points[i + 1].x()));
        }

        perimetr += qSqrt((points[0].y() - points[points.size() - 1].y())
                              * (points[0].y() - points[points.size() - 1].y())
                          + (points[0].x() - points[points.size() - 1].x())
                                * (points[0].x() - points[points.size() - 1].x()));
    }
    perimetr = perimetr * 2 + 2;
}
