#include "ellipse.h"
#include "pointsMath.h"

ellipse::ellipse()
{
    setPoints(new QPointF[3]);
    setPointNeeded(3);
}

ellipse::~ellipse()
{
    delete [] getPoints();
}

double ellipse::getSquare()
{
    double axis_y = distanceToLine(getPoints()[0], getPoints()[1], getPoints()[2]);
    double axis_x = distance(getPoints()[1], getPoints()[2]);

    return acos(-1) * axis_y * axis_x;
}

double ellipse::getPerimeter()
{
    double axis_y = distanceToLine(getPoints()[0], getPoints()[1], getPoints()[2]);
    double axis_x = distance(getPoints()[1], getPoints()[2]);

    return acos(-1) * (3 * (axis_y + axis_x) - sqrt((3 * axis_y + axis_x) * (3 * axis_y + axis_x)));
}

void ellipse::setFigure(QPointF* points)
{
    setPoints(points);

    getMassCenter()->setX(getPoints()[1].x());
    getMassCenter()->setY(getPoints()[1].y());
}

bool ellipse::isPointInside(QPointF point)
{
    double axis_y = distanceToLine(getPoints()[0], getPoints()[1], getPoints()[2]);
    double axis_x = distance(getPoints()[1], getPoints()[2]);

    double alpha = -atan(((getPoints()[2].y()) - getMassCenter()->y()) / (getPoints()[2].x() - getMassCenter()->x()));

    QPointF centered_point(point.x() - getMassCenter()->x(), point.y() - getMassCenter()->y());
    QPointF translated_point(centered_point.x() * cos(alpha) - centered_point.y() * sin(alpha),
                             centered_point.y() * cos(alpha) + centered_point.x() * sin(alpha));

    return (translated_point.x() * translated_point.x() / (axis_x * axis_x) + translated_point.y() * translated_point.y() / (axis_y * axis_y)) <= 1;
}

void ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    double axis_y = distanceToLine(getPoints()[0], getPoints()[1], getPoints()[2]);
    double axis_x = distance(getPoints()[1], getPoints()[2]);

    double alpha = atan(((getPoints()[2].y()) - getMassCenter()->y()) / (getPoints()[2].x() - getMassCenter()->x()));

    painter->save();
    painter->translate(*getMassCenter());
    painter->rotate(alpha / acos(-1) * HALF_OF_CIRCLE_IN_DEGREES);
    painter->drawEllipse(-axis_x, -axis_y, 2*axis_x, 2*axis_y);
    painter->restore();
}

QRectF ellipse::boundingRect() const
{
    return QRectF(QPoint(std::min({ this->getPoints()[0].x(), this->getPoints()[1].x(), this->getPoints()[2].x() }),
                         std::max({ this->getPoints()[0].y(), this->getPoints()[1].y(), this->getPoints()[2].y() })),
                  QPoint(std::max({ this->getPoints()[0].x(), this->getPoints()[1].x(), this->getPoints()[2].x() }),
                         std::min({ this->getPoints()[0].y(), this->getPoints()[1].y(), this->getPoints()[2].y() })));
}
