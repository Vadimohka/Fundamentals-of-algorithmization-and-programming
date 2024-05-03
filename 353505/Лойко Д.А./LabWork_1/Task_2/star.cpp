#include "star.h"

void star::sumPoints(int n) {
    points.resize(n * 2);
    double xp = mousePress.x(),
        xn = mouseNow.x(),
        yp = mousePress.y(),
        yn = mouseNow.y();

    if (isShift) {
        double max = qMax(qAbs(xp - xn), qAbs(yp - yn));
        xp > xn ? xn = xp - max : xn = xp + max;
        yp > yn ? yn = yp - max : yn = yp + max;

    }

    double b = (xn - xp) / 2,
        a = (yn - yp) / 2;

    double xc = (xp + xn) / 2,
        yc = (yp + yn) / 2;


    for (int i = 0; i < n; i++) {
        QPointF p_out, p_in;
        p_out = {
            xc - b * qSin(2 * M_PI / n * i),
            yc - a * qCos(2 * M_PI / n * i)
        };

        p_in = {
            xc - b / 2 * qSin(2 * M_PI / n * i + M_PI / n),
            yc - a / 2 * qCos(2 * M_PI / n * i + M_PI / n)
        };
        points[i * 2] = p_out;
        points[i * 2 + 1] = p_in;
    }


}
