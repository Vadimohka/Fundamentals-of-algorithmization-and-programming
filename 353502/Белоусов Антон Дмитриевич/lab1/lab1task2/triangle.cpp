#include "triangle.h"
#include "pointsMath.h"

triangle::triangle()
{
    setPoints(new QPointF[3]);
    setPointNeeded(3);
}

triangle::~triangle()
{
    delete [] getPoints();
}

double triangle::getSquare()
{
    double perimeter = this->getPerimeter() / 2;

    return std::sqrt( perimeter *
                     (perimeter - distance(getPoints()[0], getPoints()[1])) *
                     (perimeter - distance(getPoints()[1], getPoints()[2])) *
                     (perimeter - distance(getPoints()[2], getPoints()[0])));
}

double triangle::getPerimeter()
{
    return distance(getPoints()[0], getPoints()[1]) + distance(getPoints()[1], getPoints()[2]) + distance(getPoints()[2], getPoints()[0]);
}

void triangle::setFigure(QPointF* points)
{
    setPoints(points);

    getMassCenter()->setX((getPoints()[0].x() + getPoints()[1].x() + getPoints()[2].x()) / 3);
    getMassCenter()->setY((getPoints()[0].y() + getPoints()[1].y() + getPoints()[2].y()) / 3);
}

bool triangle::isPointInside(QPointF point)
{
    int intersectionCount
        = static_cast<int>(isHorizontalRightRayIntersectingSegment(point, getPoints()[0], getPoints()[1]))
          + static_cast<int>(isHorizontalRightRayIntersectingSegment(point, getPoints()[1], getPoints()[2]))
          + static_cast<int>(isHorizontalRightRayIntersectingSegment(point, getPoints()[2], getPoints()[0]));

    return (intersectionCount % 2) != 0;
}

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawLine(getPoints()[0], getPoints()[1]);
    painter->drawLine(getPoints()[1], getPoints()[2]);
    painter->drawLine(getPoints()[2], getPoints()[0]);
}

QRectF triangle::boundingRect() const
{
    return QRectF(QPointF(std::min({ getPoints()[0].x(), getPoints()[1].x(), getPoints()[2].x() }),
                         std::max({ getPoints()[0].y(), getPoints()[1].y(), getPoints()[2].y() })),
                  QPointF(std::max({ getPoints()[0].x(), getPoints()[1].x(), getPoints()[2].x() }),
                         std::min({ getPoints()[0].y(), getPoints()[1].y(), getPoints()[2].y() })));
}
