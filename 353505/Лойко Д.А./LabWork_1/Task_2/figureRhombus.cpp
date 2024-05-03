#include "figureRhombus.h"


void figureRhombus::setPoints(QMouseEvent *me) {
    mouseNow = me->pos();
    points.resize(4);
    if (!isShift) {
        points = {
            {(double)(((double)mousePress.x() + (double)mouseNow.x()) / 2), (double)mousePress.y()},
            {(double)mousePress.x(), (double)(((double)mousePress.y() + (double)mouseNow.y()) / 2)},
            {(double)(((double)mousePress.x() + (double)mouseNow.x()) / 2), (double)mouseNow.y()},
            {(double)mouseNow.x(),   (double)(((double)mouseNow.y() + (double)mousePress.y()) / 2)}
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
            {(xm + xp) / 2, yp},
            {xp, (ym + yp) / 2},
            {(xp + xm) / 2, ym},
            {xm, (yp + ym) / 2}
        };
    }

}
