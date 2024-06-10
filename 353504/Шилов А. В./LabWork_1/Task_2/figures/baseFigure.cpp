//
// Created by darina on 3/10/24.
//

#include "baseFigure.h"

baseFigure::baseFigure(int n, qreal xCenter, qreal yCenter, qreal xFinish, qreal yFinish) :
rotateAngle(0),
points(new std::pair<qreal, qreal>[n]),
basePoints(new std::pair<qreal, qreal>[n]) {
    x1 = xCenter;
    x2 = xFinish;
    y1 = yCenter;
    y2 = yFinish;
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    moveX = 0;
    moveY = 0;

}

QRectF baseFigure::boundingRect() const {
    return {0, 0, 0, 0};
}

qreal dist(qreal x1, qreal y1, qreal x2, qreal y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

qreal square(qreal x1, qreal y1, qreal x2, qreal y2, qreal x3, qreal y3) {
    qreal a = dist(x1, y1, x2, y2);
    qreal b = dist(x3, y3, x2, y2);
    qreal c = dist(x1, y1, x3, y3);
    const int two = 2;
    qreal p = (a + b + c) / two;
    return sqrt(p * abs(p - a) * abs(p - b) * abs(p - c));
}

void baseFigure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    setPoints();

    painter->setPen(Qt::black);
    for (int i = 1; i < numPoints; i++) {
        painter->drawLine(points[i - 1].first, points[i - 1].second, points[i].first, points[i].second);
    }

    painter->drawLine(points[0].first, points[0].second, points[numPoints - 1].first, points[numPoints - 1].second);
    painter->setPen(Qt::red);

    painter->drawEllipse(xCenter - 3 + moveX, yCenter - 3 + moveY, six, six);

    update();
}

std::pair<qreal, qreal> baseFigure::rotate(qreal x, qreal y, qreal angle) {
    return {x * cos(angle) - y * sin(angle),
            x * sin(angle) + y * cos(angle)};
}

std::pair<qreal, qreal> baseFigure::changeSize(qreal x, qreal y) const {
    if (equal) {
        qreal t = std::max(abs(x1 - x2), abs(y1 - y2));
        return {x * ((x1 > x2) ? t : -t),
                y * ((y1 > y2) ? t : -t)};
    }
    return {x * (x1 - x2),
            y * (y1 - y2)};
}

std::pair<qreal, qreal> baseFigure::move(qreal x, qreal y) const {
    return {x + x1, y + y1};
}


void baseFigure::setPoints() {
    for (int i = 0; i < numPoints; i++) {
        std::pair<qreal, qreal> point = changeSize(basePoints[i].first, basePoints[i].second);
        point = rotate(point.first, point.second, rotateAngle);
        point = move(point.first, point.second);
        point.first += moveX;
        point.second += moveY;

        points[i] = point;

    }
}

void baseFigure::rotateAll(qreal angle) {
    rotateAngle += angle;
}

void baseFigure::setX2(qreal x) {
    x2 = x;
}

void baseFigure::setY2(qreal y) {
    y2 = y;
}

void baseFigure::setDeltaX(qreal x) {
    moveX += x;
}

void baseFigure::setDeltaY(qreal y) {
    moveY += y;
}

qreal baseFigure::getPerimeter() {
    perimeter = 0.0;
    for (int i = 1; i < numPoints; i++) {
        perimeter += dist(points[i - 1].first, points[i - 1].second, points[i].first, points[i].second);
    }
    perimeter += dist(points[0].first, points[0].second, points[numPoints - 1].first, points[numPoints - 1].second);
    fullSquare += square(points[0].first, points[0].second, points[numPoints - 1].first, points[numPoints - 1].second,
                         xCenter + moveX, yCenter + moveY);

    return perimeter;
}

qreal baseFigure::getSquare() {
    fullSquare = 0.0;
    for (int i = 1; i < numPoints; i++) {
        fullSquare += square(points[i - 1].first, points[i - 1].second, points[i].first, points[i].second,
                             xCenter + moveX, yCenter + moveY);
    }
    fullSquare += square(points[0].first, points[0].second, points[numPoints - 1].first, points[numPoints - 1].second,
                         xCenter + moveX, yCenter + moveY);

    return fullSquare;
}

void baseFigure::setRadiuse(qreal delta) {
    insideRadius += delta;
    insideRadius = std::max(insideRadius, minRadiuse);
    qreal x = 0, y = -insideRadius;
    std::pair<double, double> p;
    p = rotate(x, y, M_PI / (static_cast<double>(numPoints) / 2));
    x = p.first;
    y = p.second;

    for (int i = 1; i < numPoints; i += 2) {
        basePoints[i] = {x, y};
        p = rotate(x, y, 2 * M_PI / (static_cast<double>(numPoints) / 2));
        x = p.first;
        y = p.second;
    }

    setPoints();
}

void baseFigure::setEqual() {
    equal = true;
}

std::pair<qreal, qreal> baseFigure::getCenter() const {
    return std::pair<qreal, qreal>{xCenter + moveX, yCenter + moveY};
}
