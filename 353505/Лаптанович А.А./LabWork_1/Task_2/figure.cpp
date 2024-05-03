#include "figure.h"
#include <QPainter>

Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    this->setCenterPoint();
    this->setAngle(0);

    connect(this, &Figure::pointChanged, this, &Figure::updateRomb);
}

Figure::~Figure()
{

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

qreal Figure::angle() const
{
    return m_angle;
}

qreal Figure::square()
{
    return 0;
}

qreal Figure::perimeter()
{
    return 0;
}


void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setCenterPoint()
{
    m_centerPoint = (startPoint() + endPoint()) / 2;
}

void Figure::setAngle(qreal angle)
{
    m_angle = angle;
    emit pointChanged();
}


void Figure::changePoints(QPointF deltaStart, QPointF deltaEnd)
{
    if (startPoint().x() < -300 || startPoint().x() > 1800 || endPoint().x() < -300 || endPoint().x() > 1800
        || startPoint().y() < -300 || startPoint().y() > 1200 || endPoint().y() < -300 || endPoint().y() > 1200)
        return;

    this->setAngle(this->rotation());
    this->setRotation(0);

    this->setStartPoint(deltaStart);
    this->setEndPoint(deltaEnd);
    this->setCenterPoint();

    this->setRotation(this->angle());
}

void Figure::scale(int sign)
{
    if (sign == 1 && (startPoint().x() < -300 || startPoint().x() > 1800 || endPoint().x() < -300 || endPoint().x() > 1800
                      || startPoint().y() < -300 || startPoint().y() > 1200 || endPoint().y() < -300 || endPoint().y() > 1200))
        return;

    if (sign == -1 && (QLineF(startPoint(), endPoint()).length() <= 20)) return;

    this->setAngle(this->rotation());
    this->setRotation(0);

    double coeff = abs((startPoint().x() - endPoint().x()) / (startPoint().y() - endPoint().y()));
    this->setEndPoint(QPointF(endPoint().x() + sign * coeff, endPoint().y() + sign * 1));
    this->setStartPoint(QPointF(startPoint().x() - sign * coeff, startPoint().y() - sign * 1));
    this->setRotation(this->angle());
}


void Figure::setVertexCount(int vertexCount)
{
}

void Figure::setRadiusA(qreal a)
{
}

void Figure::setRadiusB(qreal b)
{
}


QRectF Figure::boundingRect() const
{
    return QRectF(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x() - 5,
                  endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y() - 5,
                  qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateRomb()
{
    this->update();
    this->setCenterPoint();
}

