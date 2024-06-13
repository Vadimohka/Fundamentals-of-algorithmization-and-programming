#include "shape.h"

shape::shape(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem() {
    //setFlag(ItemIsMovable);

    startPoint = mapFromScene(point);
    finalPoint = mapFromScene(point);
}

QPointF shape::getStartPoint() const
{
    return startPoint;
}

QPointF shape::getFinalPoint() const
{
    return finalPoint;
}

void shape::setStartPoint(QPointF point)
{
    startPoint = point;
    length = qMax(startPoint.x(),finalPoint.x()) - qMin(startPoint.x(),finalPoint.x());
    width = qMax(startPoint.y(),finalPoint.y()) - qMin(startPoint.y(),finalPoint.y());
    this->update(qMin(getStartPoint().x(),getFinalPoint().x()),
                 qMin(getStartPoint().y(),getFinalPoint().y()),
                 length, width);
}

void shape::setFinalPoint(QPointF point)
{
    finalPoint = point;
    length = qMax(startPoint.x(),finalPoint.x()) - qMin(startPoint.x(),finalPoint.x());
    width = qMax(startPoint.y(),finalPoint.y()) - qMin(startPoint.y(),finalPoint.y());
    this->update(qMin(getStartPoint().x(),getFinalPoint().x()),
                 qMin(getStartPoint().y(),getFinalPoint().y()),
                 length, width);
}

QRectF shape::boundingRect() const
{
    return QRectF(qMin(getStartPoint().x(),getFinalPoint().x()),
                  qMin(getStartPoint().y(),getFinalPoint().y()),
                  /*qMax(getStartPoint().x(),getFinalPoint().x()) - qMin(getStartPoint().x(),getFinalPoint().x()),
                  qMax(getStartPoint().y(),getFinalPoint().y()) - qMin(getStartPoint().y(),getFinalPoint().y())*/
                  length,width);
}

double shape::getS()
{
    //qDebug () << square;
    return square;
}

double shape::getP()
{
    return perim;
}

void shape::setS(double x)
{
    square = x;
}

void shape::setP(double x)
{
    perim = x;
}

void shape::incScaleFactor(double delta)
{
    if (scaleFactor+delta>0.1) {
        scaleFactor+=delta;
    }
}

double shape::getScaleFactor() const
{
    return scaleFactor;
}

void shape::incRotateFactor(int delta)
{
    rotateFactor+=delta;
}

int shape::getRotateFactor() const
{
    return rotateFactor;
}
