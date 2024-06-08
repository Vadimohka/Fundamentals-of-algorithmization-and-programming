#include "straightlinepath.h"

StraightLinePath::StraightLinePath(const QPointF& start, const QPointF& end, int points)
    : startPoint(start), endPoint(end), numPoints(points) {}

QPointF StraightLinePath::PointAt(float p) const {
    qreal x = startPoint.x() + (endPoint.x() - startPoint.x()) * p;
    qreal y = startPoint.y() + (endPoint.y() - startPoint.y()) * p;
    return QPointF(x, y);
}

int StraightLinePath::Size() const {
    return numPoints;
}
