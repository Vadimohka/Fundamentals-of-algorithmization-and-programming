#include "beziercurvepath.h"

BezierCurvePath::BezierCurvePath(const std::vector<QPointF> &pts)
    : pts(pts)
{
    assert(pts.size() % 4 == 0 && "count of points must be a multiple of 4");
}

std::vector<QPointF> BezierCurvePath::curve1H()
{
    std::vector<QPointF> controlPoints;
    controlPoints.push_back(QPointF(390, 15));
    controlPoints.push_back(QPointF(440, 110));
    controlPoints.push_back(QPointF(180, 140));
    controlPoints.push_back(QPointF(175, 305));
    controlPoints.push_back(QPointF(175, 305));
    controlPoints.push_back(QPointF(180, 450));
    controlPoints.push_back(QPointF(370, 430));
    controlPoints.push_back(QPointF(375, 295));
    return controlPoints;
}

std::vector<QPointF> BezierCurvePath::curve3()
{
    std::vector<QPointF> controlPoints;
    controlPoints.push_back(QPointF(176, 648));
    controlPoints.push_back(QPointF(592, 178));
    controlPoints.push_back(QPointF(178, 16));
    controlPoints.push_back(QPointF(176, 210));
    return controlPoints;
}

std::vector<QPointF> BezierCurvePath::curve3Mir()
{
    std::vector<QPointF> controlPoints;
    controlPoints.push_back(QPointF(-176, 648));
    controlPoints.push_back(QPointF(-592, 178));
    controlPoints.push_back(QPointF(-178, 16));
    controlPoints.push_back(QPointF(-176, 210));
    return controlPoints;
}

std::vector<QPointF> BezierCurvePath::curve1()
{
    std::vector<QPointF> controlPoints;
    controlPoints.push_back(QPointF(390, 15));
    controlPoints.push_back(QPointF(440, 110));
    controlPoints.push_back(QPointF(180, 140));
    controlPoints.push_back(QPointF(175, 305));
    controlPoints.push_back(QPointF(175, 305));
    controlPoints.push_back(QPointF(180, 450));
    controlPoints.push_back(QPointF(370, 430));
    controlPoints.push_back(QPointF(375, 295));
    return controlPoints;
}

std::vector<QPointF> BezierCurvePath::curve1Mir()
{
    std::vector<QPointF> controlPoints;
    controlPoints.push_back(QPointF(-390, 15));
    controlPoints.push_back(QPointF(-440, 110));
    controlPoints.push_back(QPointF(-180, 140));
    controlPoints.push_back(QPointF(-175, 305));
    controlPoints.push_back(QPointF(-175, 305));
    controlPoints.push_back(QPointF(-180, 450));
    controlPoints.push_back(QPointF(-370, 430));
    controlPoints.push_back(QPointF(-375, 295));
    return controlPoints;
}

std::vector<QPointF> BezierCurvePath::curve2()
{
    std::vector<QPointF> controlPoints;
    controlPoints.push_back(QPointF(375, 295));
    controlPoints.push_back(QPointF(370, 430));
    controlPoints.push_back(QPointF(180, 450));
    controlPoints.push_back(QPointF(175, 305));
    return controlPoints;
}

std::vector<QPointF> BezierCurvePath::circle()
{
    std::vector<QPointF> controlPoints;
    controlPoints.push_back(QPointF(0, 0));
    controlPoints.push_back(QPointF(0, 120));
    controlPoints.push_back(QPointF(-120, 120));
    controlPoints.push_back(QPointF(-120, 0));
    controlPoints.push_back(QPointF(-120, 0));
    controlPoints.push_back(QPointF(-120, -120));
    controlPoints.push_back(QPointF(0, -200));
    controlPoints.push_back(QPointF(0, 0));
    return controlPoints;
}

std::vector<QPointF> BezierCurvePath::circleRev()
{
    std::vector<QPointF> controlPoints;
    controlPoints.push_back(QPointF(0, 0));
    controlPoints.push_back(QPointF(0, -200));
    controlPoints.push_back(QPointF(-120, -120));
    controlPoints.push_back(QPointF(-120, 0));
    controlPoints.push_back(QPointF(-120, 0));
    controlPoints.push_back(QPointF(-120, 120));
    controlPoints.push_back(QPointF(0, 120));
    controlPoints.push_back(QPointF(0, 0));
    return controlPoints;
}


QPointF BezierCurvePath::PointAt(float p) const
{
    if (p < 0) {
        return QPointF();
    }

    int i = std::floor(p);
    float t = p - i;

    i *= 4;

    float x = (1 - t) * (1 - t) * (1 - t) * pts[i].x() + 3 * (1 - t) * (1 - t) * t * pts[i + 1].x()
              + 3 * (1 - t) * t * t * pts[i + 2].x() + t * t * t * pts[i + 3].x();

    float y = (1 - t) * (1 - t) * (1 - t) * pts[i].y() + 3 * (1 - t) * (1 - t) * t * pts[i + 1].y()
              + 3 * (1 - t) * t * t * pts[i + 2].y() + t * t * t * pts[i + 3].y();


    return QPointF(x, y);
}
