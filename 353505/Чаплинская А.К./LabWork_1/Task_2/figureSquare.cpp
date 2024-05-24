#include "figureSquare.h"


void figureSquare::setPoints(QMouseEvent *me) {
    mouseNow = me->pos();
    points.resize(4);
    if (!isShift) {
        points = {
            {(double)mousePress.x(), (double)mousePress.y()},
            {(double)mousePress.x(), (double)mouseNow.y()},
            {(double)mouseNow.x(),   (double)mouseNow.y()},
            {(double)mouseNow.x(),   (double)mousePress.y()}
        };
    }
    else {
        double max = qMax(qAbs(mouseNow.x() - mousePress.x()), qAbs(mouseNow.y() - mousePress.y()));
        double xp, xm, yp, ym;
        if(mouseNow.x() < mousePress.x()) {
            xm = mousePress.x();
            xp = xm - max;
        } else {
            xp = mousePress.x();
            xm = xp + max;
        }

        if(mouseNow.y() < mousePress.y()) {
            ym = mousePress.y();
            yp = ym - max;
        } else {
            yp = mousePress.y();
            ym = yp + max;
        }

        points = {
            {xp, yp},
            {xp, ym},
            {xm, ym},
            {xm, yp}
        };
    }

}
