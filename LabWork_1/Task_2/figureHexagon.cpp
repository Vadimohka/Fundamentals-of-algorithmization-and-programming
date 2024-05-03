#include "figureHexagon.h"

void figureHexagon::setPoints(QMouseEvent *me) {
    mouseNow = me->pos();
    points.resize(6);

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


    for (int i = 0; i < 6; i++) {
        QPointF p_out;
        p_out = {
            xc - b * qSin(M_PI / 3 * i) + i,
            yc - a * qCos(M_PI / 3 * i) + i
        };

        points[i] = p_out;
    }

}
