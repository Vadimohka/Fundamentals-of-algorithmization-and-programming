#include "figureCircle.h"

void figureCircle::draw(QPainter *pe) {

    int max = qMax(qAbs(mouseNow.x() - mousePress.x()), qAbs(mouseNow.y() - mousePress.y()));
    double xp, xm, yp, ym;
    if (mouseNow.x() < mousePress.x()) {
        xm = mousePress.x();
        xp = xm - max;
        /*        mousePress.setX(xm);
        mouseNow.setX(xp);*/
    } else {
        xp = mousePress.x();
        xm = xp + max;
        /*mousePress.setX(xp);
        mouseNow.setX(xm);*/
    }

    if (mouseNow.y() < mousePress.y()) {
        ym = mousePress.y();
        yp = ym - max;
        //        mousePress.setY(ym);
        //        mouseNow.setY(yp);
    } else {
        yp = mousePress.y();
        ym = yp + max;
        //        mousePress.setY(yp);
        //        mouseNow.setY(ym);
    }

    center = {(xm + xp) / 2, (ym + yp) / 2};

    pe->drawEllipse(center, (xm - xp) * scale / 2, (ym - yp) * scale / 2);
    r = qAbs(xm - xp) * scale / 2;
    findSquare();

    /*pe->drawEllipse(
            xp,
            yp,
            (int)((xm - xp) * scale),
            (int)((ym - yp) * scale)
    );*/

}

void figureCircle::move() {
    QPoint dif = mouseMoveNow - mouseMovePress;
    mousePress += dif;
    mouseNow += dif;
    mouseMovePress = mouseMoveNow;
}

void figureCircle::findSquare() {
    square = M_PI * r * r;
}

void figureCircle::findPerimeter() {
    perimeter = 2 * M_PI * r;
}
