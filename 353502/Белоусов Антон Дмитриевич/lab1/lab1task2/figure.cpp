#include "figure.h"

figure::figure() : massCenter(new QPointF)
{}

figure::~figure() = default;

void figure::rotateFigureFromPointToPoint(QPointF first_point, QPointF second_point)
{
    double centered_x1 = first_point.x() - getMassCenter()->x();
    double centered_y1 = first_point.y() - getMassCenter()->y();
    double centered_x2 = second_point.x() - getMassCenter()->x();
    double centered_y2 = second_point.y() - getMassCenter()->y();

    double delta = asin(centered_y2 / sqrt(centered_x2*centered_x2+centered_y2*centered_y2)) - asin(centered_y1 / sqrt(centered_x1*centered_x1+centered_y1*centered_y1));

    if (centered_x2 <= 0) {
        delta = -delta;
    }

    this->rotateFigure(delta);
}

void figure::resizeFigureFromPointToPoint(QPointF first_point, QPointF second_point)
{
    double centered_x1 = first_point.x() - getMassCenter()->x();
    double centered_y1 = first_point.y() - getMassCenter()->y();
    double centered_x2 = second_point.x() - getMassCenter()->x();
    double centered_y2 = second_point.y() - getMassCenter()->y();

    double delta = sqrt(centered_x2*centered_x2+centered_y2*centered_y2) / sqrt(centered_x1*centered_x1+centered_y1*centered_y1);
    this->resizeFigure(delta);
}

void figure::rotateFigure(double delta)
{
    for (int i = 0;i<getPointNeeded();i++)
    {
        double centered_x = getPoints()[i].x() - getMassCenter()->x();
        double centered_y = getPoints()[i].y() - getMassCenter()->y();
        double x_new = centered_x * cos(delta) - centered_y * sin(delta);
        double y_new = centered_y * cos(delta) + centered_x * sin(delta);

        getPoints()[i].setX(x_new + getMassCenter()->x());
        getPoints()[i].setY(y_new + getMassCenter()->y());
    }
}

void figure::resizeFigure(double delta)
{
    for (int i = 0;i<this->getPointNeeded();i++)
    {
        double centered_x = getPoints()[i].x() - getMassCenter()->x();
        double centered_y = getPoints()[i].y() - getMassCenter()->y();
        double x_new = centered_x * delta;
        double y_new = centered_y * delta;

        getPoints()[i].setX(x_new + getMassCenter()->x());
        getPoints()[i].setY(y_new + getMassCenter()->y());
    }
}

QPointF *figure::getPoints() const
{
    return this->points;
}

QPointF *figure::getMassCenter() const
{
    return this->massCenter;
}

int figure::getPointNeeded() const
{
    return this->pointsNeeded;
}

void figure::setPoints(QPointF *points)
{
    this->points = points;
}

void figure::setMassCenter(QPointF *massCentre)
{
    this->massCenter = massCentre;
}

void figure::setPointNeeded(int pointsNeeded)
{
    this->pointsNeeded = pointsNeeded;
}

void figure::moveFigure(QPointF delta)
{
    for (int i = 0;i<this->getPointNeeded();i++)
    {
        this->getPoints()[i].setX(this->getPoints()[i].x() + delta.x());
        this->getPoints()[i].setY(this->getPoints()[i].y() + delta.y());
    }

    getMassCenter()->setX(getMassCenter()->x() + delta.x());
    getMassCenter()->setY(getMassCenter()->y() + delta.y());
}
