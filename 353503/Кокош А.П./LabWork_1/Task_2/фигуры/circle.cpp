#include "circle.h"

void circle::draw(QPainter *pe)
{
    int max = qMax(qAbs(mouseCurrentPos.x() - mouseWhenPress.x()),
                   qAbs(mouseCurrentPos.y() - mouseWhenPress.y()));
    double xpress = NAN, xcurr = NAN, ypress = NAN, ycurr = NAN;
    if (mouseCurrentPos.x() < mouseWhenPress.x()) {
        xcurr = mouseWhenPress.x();
        xpress = xcurr - max;

    } else {
        xpress = mouseWhenPress.x();
        xcurr = xpress + max;
    }

    if (mouseCurrentPos.y() < mouseWhenPress.y()) {
        ycurr = mouseWhenPress.y();
        ypress = ycurr - max;

    } else {
        ypress = mouseWhenPress.y();
        ycurr = ypress + max;
    }

    center = {(xcurr + xpress) / 2, (ycurr + ypress) / 2};

    pe->drawEllipse(center, (xcurr - xpress) * scale / 2, (ycurr - ypress) * scale / 2);
    radius = qAbs(xcurr - xpress) * scale / 2;
    findSquare();
}

void circle::move()
{
    QPoint moveBy = mouseMoveCurrentPos - mouseMoveWhenPress;
    mouseWhenPress += moveBy;
    mouseCurrentPos += moveBy;
    mouseMoveWhenPress = mouseMoveCurrentPos;
}

void circle::findSquare()
{
    square = M_PI * radius * radius;
}

void circle::findPerimetr()
{
    perimetr = 2 * M_PI * radius;
}
