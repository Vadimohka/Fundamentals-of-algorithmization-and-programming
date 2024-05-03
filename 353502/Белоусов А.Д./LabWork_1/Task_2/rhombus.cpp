#include "rhombus.h"
#include "pointsMath.h"

rhombus::rhombus()
{
    setPoints(new QPointF[3]);
    setPointNeeded(3);
}

rhombus::~rhombus()
{
    delete [] getPoints();
}

double rhombus::getSquare()
{
    double axis_y = distanceToLine(getPoints()[0], getPoints()[1], getPoints()[2]);
    double axis_x = distance(getPoints()[1], getPoints()[2]);

    return 2 * axis_y * axis_x;
}

double rhombus::getPerimeter()
{
    return 4 * distance(getPoints()[0], getPoints()[2]);
}

void rhombus::setFigure(QPointF* points)
{
    setPoints(points);

    getMassCenter()->setX(getPoints()[1].x());
    getMassCenter()->setY(getPoints()[1].y());

    double axis_y = distanceToLine(getPoints()[0], getPoints()[1], getPoints()[2]);

    double alpha = atan(((getPoints()[2].y()) - getMassCenter()->y()) / (getPoints()[2].x() - getMassCenter()->x()));
    alpha -= acos(-1) / 2;

    this->getPoints()[0] = QPointF(getMassCenter()->x() - axis_y * cos(alpha), getMassCenter()->y() - axis_y * sin(alpha));
}

bool rhombus::isPointInside(QPointF point)
{
    int dx1 = getPoints()[0].x() - getPoints()[1].x();
    int dy1 = getPoints()[0].y() - getPoints()[1].y();
    int dx2 = getPoints()[2].x() - getPoints()[1].x();
    int dy2 = getPoints()[2].y() - getPoints()[1].y();

    QPointF point_d1(getPoints()[1].x() - dx1, getPoints()[1].y() - dy1);
    QPointF point_d2(getPoints()[1].x() - dx2, getPoints()[1].y() - dy2);

    int intersectionCount = 0;

    if (isHorizontalRightRayIntersectingSegment(point, getPoints()[0], getPoints()[2]))
    {
        intersectionCount++;
    }
    if (isHorizontalRightRayIntersectingSegment(point, getPoints()[2], point_d1))
    {
        intersectionCount++;
    }
    if (isHorizontalRightRayIntersectingSegment(point, point_d1, point_d2))
    {
        intersectionCount++;
    }
    if (isHorizontalRightRayIntersectingSegment(point, point_d2, getPoints()[0]))
    {
        intersectionCount++;
    }

    return (intersectionCount % 2 == 1);
}

void rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int dx1 = getPoints()[0].x() - getPoints()[1].x();
    int dy1 = getPoints()[0].y() - getPoints()[1].y();
    int dx2 = getPoints()[2].x() - getPoints()[1].x();
    int dy2 = getPoints()[2].y() - getPoints()[1].y();

    QPointF point_d1(getPoints()[1].x() - dx1, getPoints()[1].y() - dy1);
    QPointF point_d2(getPoints()[1].x() - dx2, getPoints()[1].y() - dy2);

    painter->drawLine(getPoints()[0], getPoints()[2]);
    painter->drawLine(getPoints()[2], point_d1);
    painter->drawLine(point_d1, point_d2);
    painter->drawLine(point_d2, getPoints()[0]);
}

QRectF rhombus::boundingRect() const
{
    int dx1 = getPoints()[0].x() - getPoints()[1].x();
    int dy1 = getPoints()[0].y() - getPoints()[1].y();
    int dx2 = getPoints()[2].x() - getPoints()[1].x();
    int dy2 = getPoints()[2].y() - getPoints()[1].y();
    QPointF point_d1(getPoints()[1].x() - dx1, getPoints()[1].y() - dy1);
    QPointF point_d2(getPoints()[1].x() - dx2, getPoints()[1].y() - dy2);

    return QRectF(QPoint(std::min({ this->getPoints()[0].x(), this->getPoints()[2].x(), point_d1.x(), point_d2.x() }),
                         std::max({ this->getPoints()[0].y(), this->getPoints()[2].y(), point_d1.y(), point_d2.y()  })),
                  QPoint(std::max({ this->getPoints()[0].x(), this->getPoints()[2].x(), point_d1.x(), point_d2.x()  }),
                         std::min({ this->getPoints()[0].y(), this->getPoints()[2].y(), point_d1.y(), point_d2.y()  })));
}
