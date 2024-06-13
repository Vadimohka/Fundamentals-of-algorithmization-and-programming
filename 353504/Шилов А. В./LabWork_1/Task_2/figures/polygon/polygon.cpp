//
// Created by darina on 3/11/24.
//

#include "polygon.h"


void polygon::setBase() {
    qreal x = 0, y = -1;

    for (int i = 0; i < numPoints; i++) {
        basePoints[i] = {x, y};
        points[i] = {x, y};
        auto p = rotate(x, y, 2 * M_PI / numPoints);
        x = p.first;
        y = p.second;

    }
}

polygon::polygon(int n, qreal x0, qreal y0, qreal x1, qreal y1) : baseFigure(n, x0, y0, x1, y1) {
    numPoints = n;
    setBase();

}