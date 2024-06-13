//
// Created by darina on 3/16/24.
//

#include "custom.h"

custom::custom(int n, qreal x0, qreal y0, qreal x1, qreal y1) : baseFigure(n * 2, x0, y0, x1, y1) {
    numPoints = n * 2;
    setBase();
}

void custom::setBase() {
    qreal x = 0, y = -2;
    std::pair<double, double> p;
    for (int i = 0; i < numPoints; i += 2) {
        basePoints[i] = {x, y};
        points[i] = {x, y};
        p = rotate(x, y, 2 * M_PI / (numPoints / 2));
        x = p.first;
        y = p.second;
    }

    x = 0, y = -1;
    p = rotate(x, y, 2 * M_PI / (numPoints / 2));
    x = p.first;
    y = p.second;

    for (auto i = 1; i < numPoints; i += 2) {
        basePoints[i] = {x, y};
        points[i] = {x, y};
        p = rotate(x, y, 2 * M_PI / (numPoints / 2));
        x = p.first;
        y = p.second;
    }
}
