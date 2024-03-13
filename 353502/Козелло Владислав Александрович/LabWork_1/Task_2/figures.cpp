#include "figures.h"

Figures::Figures()
{
    angle = 0;
    nowAngle = 0;
    square = 0;
    perimetr = 0;
}


void Figures::create(QPainter* painter)
{
    QPolygon polygon;
    for (int i = 0; i < pointsCount; i++)
    {
        QPoint point = {(int)points[i].x(), (int)points[i].y()};
        polygon << point;
    }
    painter->drawPolygon(polygon);
}


void Figures::move()
{
    for (int i = 0; i < pointsCount; i++)
        points[i] += (nowDragPisition - pressDragPosition);
    centerPoint += (nowDragPisition - pressDragPosition);
    pressDragPosition = nowDragPisition;
}


void Figures::mousePress(QMouseEvent *event)
{
    pressPosition = event->pos();
    nowPosition = event->pos();
}


void Figures::mouseMove(QMouseEvent *event)
{
    nowPosition = event->pos();
    setPoints(event);
}


void Figures::setPoints(QMouseEvent *)
{

}


void Figures::mouseDragPress(QMouseEvent *event)
{
    pressDragPosition = event->pos();
}


void Figures::mouseDragMove(QMouseEvent *event)
{
    nowDragPisition = event->pos();
    move();
}


void Figures::resizeMinus()
{
    for(int i = 0; i < pointsCount; i++)
    {
        points[i] = (centerPoint + 49 * points[i])/50;
    }
    updateData();
}


void Figures::resizePlus()
{
    for(int i = 0; i < pointsCount; i++)
    {
        points[i] = (- centerPoint + 50 * points[i])/49;
    }
    updateData();
}


QPointF Figures::getCenterPoint()
{
    return centerPoint;
}


int Figures::getPointsCount()
{
    return pointsCount;
}


void Figures::setCenterPoint(double x, double y)
{
    QPointF shift(x - centerPoint.x(), y - centerPoint.y());
    for(int i = 0; i < pointsCount; i++)
    {
        points[i] += shift;
    }
    centerPoint = {x, y};
}


void Figures::rotateLeft()
{
    double speed = PI/180;
    for(int i = 0; i < pointsCount; i++)
    {
        points[i] = {(points[i].x() - centerPoint.x()) * qCos(-speed) - (points[i].y() - centerPoint.y()) * qSin(-speed) + centerPoint.x(),
                     (points[i].x() - centerPoint.x()) * qSin(-speed) + (points[i].y() - centerPoint.y()) * qCos(-speed) + centerPoint.y()};
    }
    nowAngle -= speed;
}


void Figures::rotateRight()
{
    double speed = PI/180;
    for(int i = 0; i < pointsCount; i++)
    {
        points[i] = {(points[i].x() - centerPoint.x()) * qCos(speed) - (points[i].y() - centerPoint.y()) * qSin(speed) + centerPoint.x(),
                     (points[i].x() - centerPoint.x()) * qSin(speed) + (points[i].y() - centerPoint.y()) * qCos(speed) + centerPoint.y()};
    }
    nowAngle += speed;
}


QPointF Figures::rotatePoint(const QPointF center, const QPointF point, const double angle)
{
    QPointF buf;
    buf = {(point.x() - center.x()) * qCos(angle) - (point.y() - center.y()) * qSin(angle) + center.x(),
                 (point.x() - center.x()) * qSin(angle) + (point.y() - center.y()) * qCos(angle) + center.y()};
    return buf;
}


void Figures::clear()
{
    pressPosition = {0, 0};
    nowPosition = {0, 0};
    for(int i = 0; i < pointsCount; i++)
        points[i] = {0, 0};
    pointsCount = 0;
    centerPoint = {0, 0};
    nowAngle = 0;
    perimetr = 0;
    square = 0;
}


double Figures::getPerimetr()
{
    return perimetr;
}


double Figures::getSquare()
{
    return square;
}


void Figures::updateData()
{

}


double Figures::distance(QPointF point1, QPointF point2)
{
    return qSqrt((point1.x() - point2.x()) * (point1.x() - point2.x()) +
                 (point1.y() - point2.y()) * (point1.y() - point2.y()));
}


void Figures::setNewPoints(double, int)
{

}


void Figures::setParameters(double, int)
{

}


int Figures::sign(const double num)
{
    if(num > 0)
        return 1;
    else if(num < 0)
        return -1;
    else
        return 0;
}


int Figures::getFlag()
{
    return flag;
}
