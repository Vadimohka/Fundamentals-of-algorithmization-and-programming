#include "triangle.h"

Triangle::Triangle(QPointF p1, QPointF p2, QPointF p3){
    points.resize(3);
    if (isTriangle(p1, p2, p3)){
        start_p1 = p1;
        start_p2 = p2;
        start_p3 = p3;
        points[0] = p1;
        points[1] = p2;
        points[2] = p3;
    }
}

void Triangle::SetStartParams()
{
    points[0] = start_p1;
    points[1] = start_p2;
    points[2] = start_p3;
}

bool Triangle::isTriangle(const QPointF& p1, const QPointF& p2, const QPointF& p3) {
    qreal a = std::sqrt(std::pow(p2.x() - p1.x(), 2) + std::pow(p2.y() - p1.y(), 2));
    qreal b = std::sqrt(std::pow(p3.x() - p2.x(), 2) + std::pow(p3.y() - p2.y(), 2));
    qreal c = std::sqrt(std::pow(p1.x() - p3.x(), 2) + std::pow(p1.y() - p3.y(), 2));

    if ((a + b > c) && (b + c > a) && (c + a > b)) {
        return true;
    } else {
        return false;
    }
}

void Triangle::findSquareTriangle()
{
    squareTR = 0;
    qreal a = std::sqrt(std::pow(points[1].x() - points[0].x(), 2) + std::pow(points[1].y() - points[0].y(), 2));
    qreal b = std::sqrt(std::pow(points[2].x() - points[1].x(), 2) + std::pow(points[2].y() - points[1].y(), 2));
    qreal c = std::sqrt(std::pow(points[0].x() - points[2].x(), 2) + std::pow(points[0].y() - points[2].y(), 2));
    qreal s = (a + b + c) / 2.0;
    squareTR = std::sqrt(s * (s - a) * (s - b) * (s - c));
}

qreal Triangle::GetSquareTriangle()
{
    return squareTR;
}

void Triangle::SetNewCoord(QPointF p1, QPointF p2, QPointF p3)
{
    if (isTriangle(p1, p2, p3)){
        points[0] = p1;
        points[1] = p2;
        points[2] = p3;
    }
}
