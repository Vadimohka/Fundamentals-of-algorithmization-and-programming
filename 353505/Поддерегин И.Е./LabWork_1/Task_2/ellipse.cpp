#include <QPainter>
#include "ellipse.h"

#define PI 3.1415926535897932

Ellipse::Ellipse(QPointF point, QObject *parent)
    : Shape(point, parent)
{
    Q_UNUSED(point);
}

Ellipse::~Ellipse()
{

}


qreal Ellipse::square()
{
    return PI * m_radiusA * m_radiusB;
}

qreal Ellipse::perimeter()
{
    return 4 * (PI * m_radiusA * m_radiusB + m_radiusA - m_radiusB) / (m_radiusA + m_radiusB);
}


void Ellipse::changeRadiuses(qreal a, qreal b)
{
    if (endPoint().x() > startPoint().x()) {
        setEndPoint(QPointF(startPoint().x() + 2 * a, endPoint().y()));
    } else {
        setStartPoint(QPointF(endPoint().x() + 2 * a, startPoint().y()));
    }

    if (endPoint().y() > startPoint().y()) {
        setEndPoint(QPointF(endPoint().x(), startPoint().y() + 2 * b));
    } else {
        setStartPoint(QPointF(startPoint().x(), endPoint().y() + 2 * b));
    }
}


void Ellipse::setRadiusA(qreal a)
{
    if (endPoint().x() > startPoint().x())
    {
        setEndPoint(QPointF(startPoint().x() + 2 * a, endPoint().y()));
    } else
    {
        setStartPoint(QPointF(endPoint().x() + 2 * a, startPoint().y()));
    }
}

void Ellipse::setRadiusB(qreal b)
{
    if (endPoint().y() > startPoint().y())
    {
        setEndPoint(QPointF(endPoint().x(), startPoint().y() + 2 * b));
    } else
    {
        setStartPoint(QPointF(startPoint().x(), endPoint().y() + 2 * b));
    }
}


void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setTransformOriginPoint(centerPoint());

    painter->setPen(QPen(Qt::black, 2));

    m_radiusA = qAbs(endPoint().x() - startPoint().x()) / 2;
    m_radiusB = qAbs(endPoint().y() - startPoint().y()) / 2;

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                m_radiusA * 2, m_radiusB * 2);

    painter->drawEllipse(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}


// радиусы
