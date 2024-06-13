#include "figure.h"

#include <QGraphicsScene>
#include <QPainter>

Figure::Figure(QPointF point, QObject *parent) : QObject (parent), QGraphicsItem()
{
    this->setFlag(ItemIsSelectable);
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));

    m_lastMousePos = QPointF();

    connect(this, &Figure::pointChanged, this, &Figure::updateFigure);
}

QRectF Figure::boundingRect() const
{
    return {(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - delta1,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - delta1,
                  qAbs(endPoint().x() - startPoint().x()) + delta2,
                  qAbs(endPoint().y() - startPoint().y()) + delta2};
}

void Figure::updateFigure()
{
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - delta1,
                 (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - delta1,
                 qAbs(endPoint().x() - startPoint().x()) + delta2,
                 qAbs(endPoint().y() - startPoint().y()) + delta2);
}

void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
}

void Figure::setCenterPoint()
{
    m_centerPoint = QPointF((m_endPoint.x() + m_startPoint.x()) / 2, (m_endPoint.y() + m_startPoint.y()) / 2);
}

QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QPointF Figure::endPoint() const
{
    return m_endPoint;
}

QPointF Figure::centerPoint() const
{
    return m_centerPoint;
}
