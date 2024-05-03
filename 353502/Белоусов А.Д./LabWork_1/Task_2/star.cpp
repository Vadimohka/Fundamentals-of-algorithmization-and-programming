#include "star.h"
#include "pointsMath.h"

star::star()
{
    setPoints(new QPointF[3]);
    setPointNeeded(3);
}

star::~star() = default;

double star::getSquare()
{
    double alpha = acos(-1) / numberOfEdges;
    double currAngle = atan((getPoints()[1].y() - getMassCenter()->y())/(getPoints()[1].x() - getMassCenter()->x()));
    double radius = distance(getPoints()[0], getPoints()[1]) / 2;

    if ((getPoints()[1].x() - getMassCenter()->x()) < 0) {
        currAngle += acos(-1);
    }

    QPointF end(getMassCenter()->x() + radius * cos(currAngle), getMassCenter()->y() + radius * sin(currAngle));
    QPointF left(getMassCenter()->x() + radius * cos(currAngle - alpha)/3, getMassCenter()->y() + radius * sin(currAngle - alpha)/3);

    return radius * distanceToLine(left, end, *getMassCenter());
}

double star::getPerimeter()
{
    double alpha = acos(-1) / numberOfEdges;
    double currAngle = atan((getPoints()[1].y() - getMassCenter()->y())/(getPoints()[1].x() - getMassCenter()->x()));
    double radius = distance(getPoints()[0], getPoints()[1]) / 2;

    if ((getPoints()[1].x() - getMassCenter()->x()) < 0) {
        currAngle += acos(-1);
    }

    QPointF end(getMassCenter()->x() + radius * cos(currAngle), getMassCenter()->y() + radius * sin(currAngle));
    QPointF left(getMassCenter()->x() + radius * cos(currAngle - alpha)/3, getMassCenter()->y() + radius * sin(currAngle - alpha)/3);

    return 2 * distance(end, left) * numberOfEdges;
}

void star::setFigure(QPointF* points)
{
    setPoints(points);

    getMassCenter()->setX((getPoints()[0].x() + getPoints()[1].x()) / 2);
    getMassCenter()->setY((getPoints()[0].y() + getPoints()[1].y()) / 2);
}

void star::setNumberOfEdges(int numberOfEdges)
{
    this->numberOfEdges = numberOfEdges;
}

bool star::isPointInside(QPointF point)
{
    int intersectionCount = 0;

    double alpha = acos(-1) / numberOfEdges;
    double currAngle = atan((getPoints()[1].y() - getMassCenter()->y())/(getPoints()[1].x() - getMassCenter()->x()));
    double radius = distance(getPoints()[0], getPoints()[1]) / 2;

    if ((getPoints()[1].x() - getMassCenter()->x()) < 0) {
        currAngle += acos(-1);
    }

    for (int i = 0;i<numberOfEdges;i++)
    {
        QPointF end(getMassCenter()->x() + radius * cos(currAngle), getMassCenter()->y() + radius * sin(currAngle));
        QPointF left(getMassCenter()->x() + radius * cos(currAngle - alpha)/3, getMassCenter()->y() + radius * sin(currAngle - alpha)/3);
        QPointF right(getMassCenter()->x() + radius * cos(currAngle + alpha)/3, getMassCenter()->y() + radius * sin(currAngle + alpha)/3);
        intersectionCount += static_cast<int>(
            isHorizontalRightRayIntersectingSegment(point, left, end));
        intersectionCount += static_cast<int>(
            isHorizontalRightRayIntersectingSegment(point, right, end));
        currAngle+=2*alpha;
    }

    return (intersectionCount % 2) != 0;
}

void star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    double alpha = acos(-1) / numberOfEdges;
    double currAngle = atan((getPoints()[1].y() - getMassCenter()->y())/(getPoints()[1].x() - getMassCenter()->x()));
    double radius = distance(getPoints()[0], getPoints()[1]) / 2;

    if ((getPoints()[1].x() - getMassCenter()->x()) < 0) {
        currAngle += acos(-1);
    }

    for (int i = 0;i<numberOfEdges;i++)
    {
        QPointF end(getMassCenter()->x() + radius * cos(currAngle), getMassCenter()->y() + radius * sin(currAngle));
        QPointF left(getMassCenter()->x() + radius * cos(currAngle - alpha)/3, getMassCenter()->y() + radius * sin(currAngle - alpha)/3);
        QPointF right(getMassCenter()->x() + radius * cos(currAngle + alpha)/3, getMassCenter()->y() + radius * sin(currAngle + alpha)/3);

        painter->drawLine(left, end);
        painter->drawLine(right, end);
        currAngle+=2*alpha;
    }
}

QRectF star::boundingRect() const
{
    return QRectF(QPoint(std::min({ this->getPoints()[0].x(), this->getPoints()[1].x(), this->getPoints()[2].x() }),
                         std::max({ this->getPoints()[0].y(), this->getPoints()[1].y(), this->getPoints()[2].y() })),
                  QPoint(std::max({ this->getPoints()[0].x(), this->getPoints()[1].x(), this->getPoints()[2].x() }),
                         std::min({ this->getPoints()[0].y(), this->getPoints()[1].y(), this->getPoints()[2].y() })));
}
