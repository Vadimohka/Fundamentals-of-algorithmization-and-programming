#include "figures.h"

void figures::move() {
    QPoint dif = mouseMoveNow - mouseMovePress;
    for (auto &point: points) {
        point += dif;
    }
    center += dif;
    mouseMovePress = mouseMoveNow;
}

void figures::resize() {
    for (auto &a: points) {
        a = center + (a - center) / lastScale * scale;
    }
}

figures::figures() = default;

void figures::draw(QPainter *qp) {
    QPolygon p;
    for (auto a: points) {
        QPoint q = {(int) a.x(), (int) a.y()};
        p << q;
    }
    findSquare();
    findPerimeter();
    qp->drawPolygon(p);
}

void figures::mousePressing(QMouseEvent *me) {
    mousePress = me->pos();
    mouseNow = me->pos();
    lastDegree = 0;
    scale = 1;
    lastScale = 1;
}

void figures::mouseMoving(QMouseEvent *me) {
    mouseNow = me->pos();
    setPoints(me);
    updateCenter();
    findSquare();
    findPerimeter();
}

void figures::setPoints(QMouseEvent *) {

}

void figures::mouseMovePressing(QMouseEvent *me) {
    mouseMovePress = me->pos();
}

void figures::mouseMoveMoving(QMouseEvent *me) {
    mouseMoveNow = me->pos();
    move();
}

void figures::upScale() {
    lastScale = scale;
    scale += 0.01;
    resize();
    findSquare();
    findPerimeter();
}

void figures::downScale() {
    lastScale = scale;
    if (scale > 0.05)
        scale -= 0.01;
    resize();
    findSquare();
    findPerimeter();
}

void figures::rotateLEFT() {
    changeAngle(lastDegree - 1);
}

void figures::rotateRIGHT() {
    changeAngle(lastDegree + 1);
}

void figures::changeAngle(int newAngle) {
    double angle = (double) (newAngle - lastDegree) / 180 * M_PI;
    lastDegree = newAngle;
    for (auto &a: points) {
        double qx = center.x() + qCos(angle) * (a.x() - center.x()) - qSin(angle) * (a.y() - center.y());
        double qy = center.y() + qSin(angle) * (a.x() - center.x()) + qCos(angle) * (a.y() - center.y());
        a = {qx, qy};
    }
}

void figures::updateCenter() {
    if (points.size() == 3) center = {(points[0] + points[1] + points[2]) / 3};
    else {
        double xp = points[0].x(), xm = points[0].x(), yp = points[0].y(), ym = points[0].y();
        for (auto &a: points) {
            xp = qMin(a.x(), xp);
            xm = qMax(a.x(), xm);
            yp = qMin(a.y(), yp);
            ym = qMax(a.y(), ym);
        }
        center = {(xp + xm) / 2, (yp + ym) / 2};
    }
}

void figures::findSquare() {
    if (points.size() > 2) {
        square = 0;
        square += points[0].y() * points[points.size() - 1].x() - points[0].x() * points[points.size() - 1].y();
        for (int i = 0; i < points.size() - 1; i++) {
            square += points[i].x() * points[i + 1].y() - points[i].y() * points[i + 1].x();
        }
        square = qAbs(square) / 2;
    }
}

void figures::findPerimeter() {
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
}
