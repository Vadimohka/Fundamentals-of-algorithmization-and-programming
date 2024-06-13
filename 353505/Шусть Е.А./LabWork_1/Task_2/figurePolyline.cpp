#include "figurePolyline.h"

void figurePolyline::setPoints(QMouseEvent *me) {
    mouseNow = me->pos();
    points.push_back(mouseNow);
}

void figurePolyline::draw(QPainter *p) {
    for(int i = 0; i < points.size() - 1; i++) {
        p->drawLine(points[i], points[i + 1]);
    }
}

void figurePolyline::findSquare() {
    findPerimeter();
    square = (perimeter - 2) / 2;
}

void figurePolyline::findPerimeter() {
    perimeter = 0;
    if (points.size() > 2) {
        for (int i = 0; i < points.size() - 1; i++) {
            perimeter += qSqrt((points[i].y() - points[i + 1].y()) * (points[i].y() - points[i + 1].y()) +
                               (points[i].x() - points[i + 1].x()) * (points[i].x() - points[i + 1].x()));
        }

        perimeter += qSqrt(
            (points[0].y() - points[points.size() - 1].y()) * (points[0].y() - points[points.size() - 1].y()) +
            (points[0].x() - points[points.size() - 1].x()) * (points[0].x() - points[points.size() - 1].x()));
    }
    perimeter = perimeter * 2 + 2;
}
