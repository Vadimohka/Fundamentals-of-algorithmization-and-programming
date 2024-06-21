#include "figure.h"

constexpr int ADDITIONAL_BR_VALUE = 10;

Figure::Figure(QPointF point, QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    this->setSP(mapFromScene(point));
    this->setEP(Spoint);
}

void Figure::setSP(const QPointF point)
{
    Spoint = point;
}

QPointF Figure::getSP() const
{
    return Spoint;
}

void Figure::setEP(const QPointF point)
{
    Epoint = point;
}

QPointF Figure::getEP() const
{
    return Epoint;
}

double Figure::getPerimeter()
{
    return perimeter;
}

double Figure::getArea()
{
    return area;
}

QPointF Figure::getSEP() const
{
    return SEPoint;
}

void Figure::setPerimeter(double per)
{
    perimeter = per;
}

void Figure::setArea(double ar)
{
    area = ar;
}

//////////////events

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SEPoint.setX(Spoint.x() - Epoint.x());
    SEPoint.setY(Spoint.y() - Epoint.y());
    Q_UNUSED(event)
}

/////////////Item stuff

QRectF Figure::boundingRect() const
{
    return {QRectF((getEP().x() > getSP().x() ? getSP().x() : getEP().x()) - ADDITIONAL_BR_VALUE,
                   (getEP().y() > getSP().y() ? getSP().y() : getEP().y()) - ADDITIONAL_BR_VALUE,
                    qAbs(getEP().x() - getSP().x()) + ADDITIONAL_BR_VALUE,
                    qAbs(getEP().y() - getSP().y()) + ADDITIONAL_BR_VALUE)};
}

void Figure::upd()
{
    this->update((getEP().x() > getSP().x() ? getSP().x() : getEP().x()) - ADDITIONAL_BR_VALUE,
                 (getEP().y() > getSP().y() ? getSP().y() : getEP().y()) - ADDITIONAL_BR_VALUE,
                  qAbs(getEP().x() - getSP().x()) + ADDITIONAL_BR_VALUE,
                  qAbs(getEP().y() - getSP().y()) + ADDITIONAL_BR_VALUE);
}
