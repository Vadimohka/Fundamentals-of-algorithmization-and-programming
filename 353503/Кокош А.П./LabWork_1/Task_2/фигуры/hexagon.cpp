#include "hexagon.h"

enum { NUM_OF_POINTS = 6 };

void hexagon::setPoints(QMouseEvent *me)
{
    mouseCurrentPos = me->pos();
    points.resize(NUM_OF_POINTS);

    double xpress = mouseWhenPress.x(), xcurr = mouseCurrentPos.x(), ypress = mouseWhenPress.y(),
           ycurr = mouseCurrentPos.y();

    if (isShift) {
        double max = qMax(qAbs(xpress - xcurr), qAbs(ypress - ycurr));
        xpress > xcurr ? xcurr = xpress - max : xcurr = xpress + max;
        ypress > ycurr ? ycurr = ypress - max : ycurr = ypress + max;
    }

    double xLeft = (xcurr - xpress) / 2;
    double yLeft = (ycurr - ypress) / 2;

    double xRight = (xpress + xcurr) / 2;
    double yRight = (ypress + ycurr) / 2;

    for (int i = 0; i < NUM_OF_POINTS; i++) {
        QPointF point;

        point = {xRight - xLeft * qSin(M_PI / 3 * i) + i, yRight - yLeft * qCos(M_PI / 3 * i) + i};

        points[i] = point;
    }
}
