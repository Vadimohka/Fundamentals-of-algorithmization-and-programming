#include "figures.h"

figures::figures() {}

void figures::move()
{
    QPoint moveBy = mouseMoveCurrentPos - mouseMoveWhenPress;
    for (auto &point : points) {
        point += moveBy;
    }
    center += moveBy;
    mouseMoveWhenPress = mouseMoveCurrentPos;
}

void figures::moveByCord(int x, int y)
{
    QPointF moveBy;
    if (center.x() < x) {
        if (center.y() < y) {
            moveBy = {x - center.x(), y - center.y()};
        } else {
            moveBy = {x - center.x(), center.y() - y};
        }
    } else {
        if (center.y() < y) {
            moveBy = {center.x() - x, y - center.y()};
        } else {
            moveBy = {center.x() - x, center.y() - y};
        }
    }

    for (auto &point : points) {
        point += moveBy;
    }
    center = QPointF(x, y);
    mouseMoveWhenPress = mouseMoveCurrentPos;
}

void figures::resize()
{
    for (auto &i : points) {
        i = center + (i - center) / lastScale * scale;
    }
}

void figures::draw(QPainter *painter)
{
    QPolygon poly;
    if (points.size() != 0) {
        for (auto i : points) {
            QPoint point_i = {(int) i.x(), (int) i.y()};
            poly << point_i;
        }

        findSquare();
        findPerimetr();
        painter->drawPolygon(poly);
    }
}

void figures::mousePressing(QMouseEvent *event)
{
    mouseWhenPress = event->pos();
    mouseCurrentPos = event->pos();
    lastDegree = 0;
    scale = 1;
    lastScale = 1;
}

void figures::mouseMoving(QMouseEvent *event)
{
    mouseCurrentPos = event->pos();
    setPoints(event);
    moveCenter();
    findSquare();
    findPerimetr();
}

void figures::setPoints(QMouseEvent *) {}

void figures::mouseMovePressing(QMouseEvent *event)
{
    mouseMoveWhenPress = event->pos();
}

void figures::mouseMoveMoving(QMouseEvent *event)
{
    mouseMoveCurrentPos = event->pos();
    move();
}

void figures::upScale()
{
    lastScale = scale;
    scale += 0.01;
    resize();
    findSquare();
    findPerimetr();
}

void figures::downScale()
{
    lastScale = scale;
    if (scale > 0.05)
        scale -= 0.01;
    resize();
    findSquare();
    findPerimetr();
}

void figures::rotateLeft()
{
    angle(lastDegree - 1);
}

void figures::rotateRight()
{
    angle(lastDegree + 1);
}

void figures::angle(int newAngle)
{
    double angle = (double) (newAngle - lastDegree) / 180 * M_PI;
    lastDegree = newAngle;
    for (auto &i : points) {
        double qx = center.x() + qCos(angle) * (i.x() - center.x())
                    - qSin(angle) * (i.y() - center.y());
        double qy = center.y() + qSin(angle) * (i.x() - center.x())
                    + qCos(angle) * (i.y() - center.y());
        i = {qx, qy};
    }
}

void figures::moveCenter()
{
    if (points.size() == 3)
        center = {(points[0] + points[1] + points[2]) / 3};
    else {
        double xpress = points[0].x(), xcurr = points[0].x(), ypress = points[0].y(),
               ycurr = points[0].y();
        for (auto &a : points) {
            xpress = qMin(a.x(), xpress);
            xcurr = qMax(a.x(), xcurr);
            ypress = qMin(a.y(), ypress);
            ycurr = qMax(a.y(), ycurr);
        }
        center = {(xpress + xcurr) / 2, (ypress + ycurr) / 2};
    }
}

void figures::findSquare()
{
    if (points.size() > 2) {
        square = 0;
        square += points[0].y() * points[points.size() - 1].x()
                  - points[0].x() * points[points.size() - 1].y();
        for (int i = 0; i < points.size() - 1; i++) {
            square += points[i].x() * points[i + 1].y() - points[i].y() * points[i + 1].x();
        }
        square = qAbs(square) / 2;
    }
}

void figures::findPerimetr()
{
    perimetr = 0;
    perimetr += qSqrt((points[0].y() - points[points.size() - 1].y())
                          * (points[0].y() - points[points.size() - 1].y())
                      + (points[0].x() - points[points.size() - 1].x())
                            * (points[0].x() - points[points.size() - 1].x()));
    if (points.size() > 2) {
        for (int i = 0; i < points.size() - 1; i++) {
            perimetr += qSqrt(
                (points[i].y() - points[i + 1].y()) * (points[i].y() - points[i + 1].y())
                + (points[i].x() - points[i + 1].x()) * (points[i].x() - points[i + 1].x()));
        }
    }
}
