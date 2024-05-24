#include <cmath>
#include "straightPolygon.h"

straightPolygon::straightPolygon(int n, qreal x0, qreal y0, qreal x1, qreal y1, bool e) : baseFigure(n, x0, y0, x1,
                                                                                                     y1) {
    numPoints = n;
    setBase();
    equal = e;
}

void straightPolygon::setBase() {
    qreal x = -1, y = -1;

    for (int i = 0; i < numPoints; i++) {
        basePoints[i] = {x, y};
        points[i] = {x, y};
        auto p = rotate(x, y, 2 * M_PI / numPoints);
        x = p.first;
        y = p.second;
    }
}
