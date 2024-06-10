#include "star.h"

star::star(int n, qreal x0, qreal y0, qreal x1, qreal y1) : baseFigure(n * 2, x0, y0, x1, y1) {
    numPoints = n * 2;
    setBase();
}

void star::setBase() {
    qreal x = 0, y = -2;
    std::pair<double, double> p;
    for (int i = 0; i < numPoints; i += 2) {
        basePoints[i] = {x, y};
        points[i] = {x, y};
        p = rotate(x, y, 2 * M_PI / (static_cast<double>(numPoints) / 2));
        x = p.first;
        y = p.second;
    }

    x = 0, y = -1;
    p = rotate(x, y, M_PI / (static_cast<double>(numPoints) / 2));
    x = p.first;
    y = p.second;

    for (int i = 1; i < numPoints; i += 2) {
        basePoints[i] = {x, y};
        points[i] = {x, y};
        p = rotate(x, y, 2 * M_PI / (static_cast<double>(numPoints) / 2));
        x = p.first;
        y = p.second;
    }
}
