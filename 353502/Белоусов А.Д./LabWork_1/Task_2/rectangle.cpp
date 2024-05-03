#include "rectangle.h"
#include "pointsMath.h"

rectangle::rectangle()
{
    setPoints(new QPointF[3]);
    setPointNeeded(3);
}

rectangle::~rectangle()
{
    delete [] getPoints();
}

double rectangle::getSquare()
{
    double axis_y = distanceToLine(getPoints()[0], getPoints()[1], getPoints()[2]);
    double axis_x = distance(getPoints()[1], getPoints()[2]);

    return axis_y * axis_x;
}

double rectangle::getPerimeter()
{
    double axis_y = distanceToLine(getPoints()[0], getPoints()[1], getPoints()[2]);
    double axis_x = distance(getPoints()[1], getPoints()[2]);

    return 2 * (axis_y + axis_x);
}

void rectangle::setFigure(QPointF* points)
{
    setPoints(points);

    double axis_y = distanceToLine(getPoints()[0], getPoints()[1], getPoints()[2]);
    double alpha = atan(((getPoints()[2].y() - getPoints()[1].y()) / (getPoints()[2].x() - getPoints()[1].x())));
    alpha += acos(-1) / 2;

    getMassCenter()->setX((getPoints()[1].x() + getPoints()[2].x()) / 2 - axis_y * cos(alpha) / 2);
    getMassCenter()->setY((getPoints()[1].y() + getPoints()[2].y()) / 2 - axis_y * sin(alpha) / 2);
}

bool rectangle::isPointInside(QPointF point)
{
    QPointF pointA(getMassCenter()->x() - (getPoints()[1].x() - getMassCenter()->x()), getMassCenter()->y() - (getPoints()[1].y() - getMassCenter()->y()));
    QPointF pointB(getMassCenter()->x() - (getPoints()[2].x() - getMassCenter()->x()), getMassCenter()->y() - (getPoints()[2].y() - getMassCenter()->y()));

    int intersectionNumber
        = static_cast<int>(isHorizontalRightRayIntersectingSegment(point, getPoints()[1], getPoints()[2]))
          + static_cast<int>(isHorizontalRightRayIntersectingSegment(point, getPoints()[1], pointB))
          + static_cast<int>(isHorizontalRightRayIntersectingSegment(point, pointA, getPoints()[2]))
          + static_cast<int>(isHorizontalRightRayIntersectingSegment(point, pointA, pointB));

    return (intersectionNumber % 2) != 0;
}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPointF pointA(getMassCenter()->x() - (getPoints()[1].x() - getMassCenter()->x()), getMassCenter()->y() - (getPoints()[1].y() - getMassCenter()->y()));
    QPointF pointB(getMassCenter()->x() - (getPoints()[2].x() - getMassCenter()->x()), getMassCenter()->y() - (getPoints()[2].y() - getMassCenter()->y()));

    painter->drawLine(getPoints()[1], getPoints()[2]);
    painter->drawLine(getPoints()[1], pointB);
    painter->drawLine(pointA, getPoints()[2]);
    painter->drawLine(pointA, pointB);
}

QRectF rectangle::boundingRect() const
{
    return QRectF(QPoint(std::min({ this->getPoints()[0].x(), this->getPoints()[1].x(), this->getPoints()[2].x() }),
                         std::max({ this->getPoints()[0].y(), this->getPoints()[1].y(), this->getPoints()[2].y() })),
                  QPoint(std::max({ this->getPoints()[0].x(), this->getPoints()[1].x(), this->getPoints()[2].x() }),
                         std::min({ this->getPoints()[0].y(), this->getPoints()[1].y(), this->getPoints()[2].y() })));
}
