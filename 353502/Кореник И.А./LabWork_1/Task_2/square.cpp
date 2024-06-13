#include "square.h"

Square::Square(QWidget* parent)
    : Figure(parent) {
    this->setParent(parent);
    points.clear();
    points.resize(4);
}

void Square::setPoints(){
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

    side = sqrt(pow(xp - xm, 2) + pow(yp - ym, 2));
}

void Square::calcArea()
{
    side = sqrt(pow(points[0].x() - points[1].x(), 2) + pow(points[1].y() - points[0].y(), 2));
    area = side * side;
}

void Square::calcCentre()
{
    centre = (points[0] + points[2]) / 2;
}

void Square::calcPerimetr()
{
    side = sqrt(pow(points[0].x() - points[1].x(), 2) + pow(points[1].y() - points[0].y(), 2));
    perimetr = 4 * side;
}

