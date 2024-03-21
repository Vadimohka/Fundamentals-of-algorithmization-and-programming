#include "foursquare.h"
#include "pointsMath.h"

foursquare::foursquare()
{
    setPoints(new QPointF[2]);
    setPointNeeded(2);
}

foursquare::~foursquare()
{
    delete [] getPoints();
}

double foursquare::getSquare()
{
    double side_length = distance(getPoints()[0], getPoints()[1]) / sqrt(2);

    return side_length*side_length;
}

double foursquare::getPerimeter()
{
    double side_length = distance(getPoints()[0], getPoints()[1]) / sqrt(2);

    return 4*side_length;
}

void foursquare::setFigure(QPointF* points)
{
    setPoints(points);

    getMassCenter()->setX((getPoints()[0].x() + getPoints()[1].x()) / 2);
    getMassCenter()->setY((getPoints()[0].y() + getPoints()[1].y()) / 2);
}

bool foursquare::isPointInside(QPointF point)
{
    QPointF pointA = QPointF(getMassCenter()->x() - (getPoints()[0].y() - getMassCenter()->y()),
                             getMassCenter()->y() + (getPoints()[0].x() - getMassCenter()->x()));
    QPointF pointB = QPointF(getMassCenter()->x() + (getPoints()[0].y() - getMassCenter()->y()),
                             getMassCenter()->y() - (getPoints()[0].x() - getMassCenter()->x()));

    int intersectionCount = 0;

    if (isHorizontalRightRayIntersectingSegment(point, getPoints()[0], pointA))
    {
        intersectionCount++;
    }
    if (isHorizontalRightRayIntersectingSegment(point, getPoints()[1], pointA))
    {
        intersectionCount++;
    }
    if (isHorizontalRightRayIntersectingSegment(point, getPoints()[0], pointB))
    {
        intersectionCount++;
    }
    if (isHorizontalRightRayIntersectingSegment(point, getPoints()[1], pointB))
    {
        intersectionCount++;
    }

    return (intersectionCount % 2) != 0;
}

void foursquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPointF pointA = QPointF(getMassCenter()->x() + (getPoints()[0].y() - getMassCenter()->y()),
                             getMassCenter()->y() - (getPoints()[0].x() - getMassCenter()->x()));
    QPointF pointB = QPointF(getMassCenter()->x() - (getPoints()[0].y() - getMassCenter()->y()),
                             getMassCenter()->y() + (getPoints()[0].x() - getMassCenter()->x()));

    painter->drawLine(getPoints()[0], pointA);
    painter->drawLine(getPoints()[0], pointB );
    painter->drawLine(getPoints()[1], pointB);
    painter->drawLine(getPoints()[1], pointA);
}

QRectF foursquare::boundingRect() const
{
    return QRectF(QPoint(std::min({ this->getPoints()[0].x(), this->getPoints()[1].x(), this->getPoints()[2].x() }),
                         std::max({ this->getPoints()[0].y(), this->getPoints()[1].y(), this->getPoints()[2].y() })),
                  QPoint(std::max({ this->getPoints()[0].x(), this->getPoints()[1].x(), this->getPoints()[2].x() }),
                         std::min({ this->getPoints()[0].y(), this->getPoints()[1].y(), this->getPoints()[2].y() })));
}
