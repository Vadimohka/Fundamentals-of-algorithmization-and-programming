#include "stars.h"

void stars::numOfPoints(long long n)
{
    points.resize(n * 2);
    double xpress = mouseWhenPress.x(), xcurr = mouseCurrentPos.x(), ypress = mouseWhenPress.y(),
           ycurr = mouseCurrentPos.y();

    if (isShift) {
        double max = qMax(qAbs(xpress - xcurr), qAbs(ypress - ycurr));
        xpress > xcurr ? xcurr = xpress - max : xcurr = xpress + max;
        ypress > ycurr ? ycurr = ypress - max : ycurr = ypress + max;
    }

    double b = (xcurr - xpress) / 2, a = (ycurr - ypress) / 2;

    double xtemp = (xpress + xcurr) / 2, ytemp = (ypress + ycurr) / 2;

    for (int i = 0; i < n; i++) {
        QPointF p_out, p_in;
        p_out = {xtemp - b * qSin(2 * M_PI / n * i), ytemp - a * qCos(2 * M_PI / n * i)};

        p_in = {xtemp - b / 2 * qSin(2 * M_PI / n * i + M_PI / n),
                ytemp - a / 2 * qCos(2 * M_PI / n * i + M_PI / n)};
        points[i * 2] = p_out;
        points[i * 2 + 1] = p_in;
    }
}
