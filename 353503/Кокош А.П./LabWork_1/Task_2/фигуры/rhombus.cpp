#include "rhombus.h"

enum { NUM_OF_POINTS = 4 };

void rhombus::setPoints(QMouseEvent *event)
{
    mouseCurrentPos = event->pos();
    points.resize(NUM_OF_POINTS);
    if (!isShift) {
        points = {{(double) (((double) mouseWhenPress.x() + (double) mouseCurrentPos.x()) / 2),
                   (double) mouseWhenPress.y()},
                  {(double) mouseWhenPress.x(),
                   (double) (((double) mouseWhenPress.y() + (double) mouseCurrentPos.y()) / 2)},
                  {(double) (((double) mouseWhenPress.x() + (double) mouseCurrentPos.x()) / 2),
                   (double) mouseCurrentPos.y()},
                  {(double) mouseCurrentPos.x(),
                   (double) (((double) mouseCurrentPos.y() + (double) mouseWhenPress.y()) / 2)}};
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

        points = {{(xcurr + xpress) / 2, ypress},
                  {xpress, (ycurr + ypress) / 2},
                  {(xpress + xcurr) / 2, ycurr},
                  {xcurr, (ypress + ycurr) / 2}};
    }
}
