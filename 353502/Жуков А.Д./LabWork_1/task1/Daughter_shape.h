#ifndef DAUGHTER_SHAPE_H
#define DAUGHTER_SHAPE_H

#include "shapeMove.h"
#include <QPolygonF>

class DaughterShape : public ParentShape
{
public:
    QPolygonF paint();

private:
    int mainPoint;
    int point_x;
    QPolygonF polygon;
};

#endif // DAUGHTER_SHAPE_H
