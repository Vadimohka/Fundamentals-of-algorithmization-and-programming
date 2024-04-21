#include "figure.h"

Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    setFlag(ItemIsMovable);

    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));

    connect(this, &Figure::pointChanged, this, &Figure::updateFigure);
}

QRectF Figure::boundingRect() const
{
    return QRectF((getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x()) - 5,
                  (getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y()) - 5,
                  qAbs(getEndPoint().x() - getStartPoint().x()) + 10,
                  qAbs(getEndPoint().y() - getStartPoint().y()) + 10);
}

void Figure::updateFigure()
{
    this->update((getEndPoint().x() > getStartPoint().x() ? getStartPoint().x() : getEndPoint().x()) - 5,
                 (getEndPoint().y() > getStartPoint().y() ? getStartPoint().y() : getEndPoint().y()) - 5,
                 qAbs(getEndPoint().x() - getStartPoint().x()) + 10,
                 qAbs(getEndPoint().y() - getStartPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point)
{
    startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    endPoint = mapFromScene(point);
    emit pointChanged();
}

qreal Figure::getSFigure() const
{
    return sFigure;
}

qreal Figure::getPFigure() const
{
    return pFigure;
}

QPointF Figure::getStartPoint() const
{
    return startPoint;
}

QPointF Figure::getEndPoint() const
{
    return endPoint;
}

