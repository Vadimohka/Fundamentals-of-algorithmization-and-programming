#include "pointsMath.h"

double distance(QPointF first_point, QPointF second_point)
{
    return std::sqrt((first_point.x() - second_point.x()) * (first_point.x() - second_point.x()) + (first_point.y() - second_point.y()) * (first_point.y() - second_point.y()));
}

bool isHorizontalRightRayIntersectingSegment(QPointF startOfTheRay, QPointF first_point, QPointF second_point)
{
    if (first_point.x() == second_point.x()) {
        return (std::min(first_point.y(), second_point.y()) <= startOfTheRay.y()
                && std::max(first_point.y(), second_point.y()) >= startOfTheRay.y()
                && first_point.x() >= startOfTheRay.x());
    }

    double line_k2 = (static_cast<double>(first_point.y()) - static_cast<double>(second_point.y()))
                     / (static_cast<double>(first_point.x())
                        - static_cast<double>(second_point.x()));
    double line_b2 = first_point.y() - line_k2 * first_point.x();

    if (first_point.y() == second_point.y())
    {
        return (startOfTheRay.y() == line_b2 && std::max(first_point.x(), second_point.x()) >= startOfTheRay.x());
    }

    double inter_y = startOfTheRay.y();
    double inter_x = (inter_y - line_b2) / line_k2;

    return (std::min(first_point.x(), second_point.x()) <= inter_x && std::max(first_point.x(), second_point.x()) >= inter_x && std::min(first_point.y(), second_point.y()) <= inter_y && std::max(first_point.y(), second_point.y()) >= inter_y && inter_x >= startOfTheRay.x());
}

double distanceToLine(QPointF point, QPointF first_point, QPointF second_point)
{
    if (first_point.x() == second_point.x()) {
        return fabs(point.x() - first_point.x());
    }
    if (first_point.y() == second_point.y()) {
        return fabs(point.y() - first_point.y());
    }

    double line_k1 = (static_cast<double>(first_point.y()) - static_cast<double>(second_point.y()))
                     / (static_cast<double>(first_point.x())
                        - static_cast<double>(second_point.x()));
    double line_b1 = first_point.y() - line_k1 * first_point.x();

    double line_k2 = -1 / line_k1;
    double line_b2 = point.y() - line_k2 * point.x();

    double inter_x = (line_b2 - line_b1) / (line_k1 - line_k2);
    double inter_y = inter_x * line_k1 + line_b1;

    return distance(point, QPointF(inter_x, inter_y));
}
