#include "hexagon.h"
#include "pointsMath.h"

hexagon::hexagon()
{
    setPoints(new QPointF[2]);
    setPointNeeded(2);
}

hexagon::~hexagon()
{
    delete [] getPoints();
}

double hexagon::getSquare()
{
    double radius = distance(getPoints()[0], getPoints()[1]) / 2;

    return (3 * sqrt(3) * (radius / 2) * (radius / 2)) / 2;
}

double hexagon::getPerimeter()
{
    double radius = distance(getPoints()[0], getPoints()[1]) / 2;

    return 3 * radius;
}

void hexagon::setFigure(QPointF* points)
{
    setPoints(points);

    getMassCenter()->setX((getPoints()[0].x() + getPoints()[1].x()) / 2);
    getMassCenter()->setY((getPoints()[0].y() + getPoints()[1].y()) / 2);
}

bool hexagon::isPointInside(QPointF point)
{
    int intersectionCount = 0;

    double alpha = acos(-1) / 3;
    double currAngle = atan((getPoints()[1].y() - getMassCenter()->y())/(getPoints()[1].x() - getMassCenter()->x()));
    double radius = distance(getPoints()[0], getPoints()[1]) / 2;

    if ((getPoints()[1].x() - getMassCenter()->x()) < 0)
    {
        currAngle += acos(-1);
    }

    for (int i = 0;i<NUMBER_OF_SIDES;i++)
    {
        QPointF end(getMassCenter()->x() + radius * cos(currAngle), getMassCenter()->y() + radius * sin(currAngle));
        QPointF start(getMassCenter()->x() + radius * cos(currAngle + alpha), getMassCenter()->y() + radius * sin(currAngle + alpha));
        if (isHorizontalRightRayIntersectingSegment(point, start, end)) {
            intersectionCount++;
        }
        currAngle+=alpha;
    }

    return intersectionCount % 2 == 1;
}

void hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    double alpha = acos(-1) / 3;
    double currAngle = atan((getPoints()[1].y() - getMassCenter()->y())/(getPoints()[1].x() - getMassCenter()->x()));
    double radius = distance(getPoints()[0], getPoints()[1]) / 2;

    if ((getPoints()[1].x() - getMassCenter()->x()) < 0)
    {
        currAngle += acos(-1);
    }

    for (int i = 0;i<NUMBER_OF_SIDES;i++)
    {
        QPointF end(getMassCenter()->x() + radius * cos(currAngle), getMassCenter()->y() + radius * sin(currAngle));
        QPointF start(getMassCenter()->x() + radius * cos(currAngle + alpha), getMassCenter()->y() + radius * sin(currAngle + alpha));
        painter->drawLine(start, end);
        currAngle+=alpha;
    }
}

QRectF hexagon::boundingRect() const
{
    return QRectF(QPoint(std::min({ this->getPoints()[0].x(), this->getPoints()[1].x(), this->getPoints()[2].x() }),
                         std::max({ this->getPoints()[0].y(), this->getPoints()[1].y(), this->getPoints()[2].y() })),
                  QPoint(std::max({ this->getPoints()[0].x(), this->getPoints()[1].x(), this->getPoints()[2].x() }),
                         std::min({ this->getPoints()[0].y(), this->getPoints()[1].y(), this->getPoints()[2].y() })));
}

