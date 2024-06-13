#include "square.h"

enum { NUM_OF_POINTS = 4 };

square::square() {}

void square::setPoints(QMouseEvent *event)
{
    mouseCurrentPos = event->pos();
    points.resize(NUM_OF_POINTS);
    if (!isShift) {
        points = {{(double) mouseWhenPress.x(), (double) mouseWhenPress.y()},
                  {(double) mouseWhenPress.x(), (double) mouseCurrentPos.y()},
                  {(double) mouseCurrentPos.x(), (double) mouseCurrentPos.y()},
                  {(double) mouseCurrentPos.x(), (double) mouseWhenPress.y()}};
    } else {
        double max = qMax(qAbs(mouseCurrentPos.x() - mouseWhenPress.x()),
                          qAbs(mouseCurrentPos.y() - mouseWhenPress.y()));
        double xpress, xcurr, ypress, ycurr;
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

        points = {{xpress, ypress}, {xpress, ycurr}, {xcurr, ycurr}, {xcurr, ypress}};
    }
}
