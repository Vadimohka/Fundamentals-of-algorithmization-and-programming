#include <QPainter>

#include "star.h"


Star::Star(QPointF point, QObject *parent)
    : RegularPolygon(point,parent)
{
    Q_UNUSED(point);
}

Star::~Star()
{

}


void Star::setSquare(QVector<QPointF> points)
{
    qreal s1 = m_innerRadius.x() * m_innerRadius.y() * m_vertexCount * sin(2 * PI / m_vertexCount) / 2;
    qreal s2 = m_vertexCount * QLineF(points[1], points[m_vertexCount - 1]).length() *
               QLineF(points[0], (points[1] + points[m_vertexCount - 1]) / 2).length() / 2;
    m_square = s1 + s2;
}


void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    m_outerRadius = QPointF(abs((startPoint().x() - endPoint().x()) / 2),
                            abs((startPoint().y() - endPoint().y()) / 2));
    m_innerRadius = m_outerRadius / 2;
    m_angleIncrement = 2 * PI / m_vertexCount;

    setTransformOriginPoint(centerPoint());

    painter->setPen(QPen(Qt::black, 2));

    QVector<QPointF> starPoints;

    qreal outerX, outerY, innerX, innerY;
    qreal minX = fmin(startPoint().x(), endPoint().x());
    qreal minY = fmin(startPoint().y(), endPoint().y());

    for (int i = 0; i < m_vertexCount; ++i)
    {
        outerX = minX + m_outerRadius.x() * cos(i * m_angleIncrement) + m_outerRadius.x();
        outerY = minY + m_outerRadius.y() * sin(i * m_angleIncrement) + m_outerRadius.y();

        starPoints.append(QPointF(outerX, outerY));

        innerX = minX + m_innerRadius.x() * cos((i + 0.5) * m_angleIncrement) + m_outerRadius.x();
        innerY = minY + m_innerRadius.y() * sin((i + 0.5) * m_angleIncrement) + m_outerRadius.y();

        starPoints.append(QPointF(innerX, innerY));
    }
    this->setPerimeter(starPoints);
    this->setSquare(starPoints);

    painter->drawPolygon(starPoints.data(), starPoints.size());


    Q_UNUSED(option)
    Q_UNUSED(widget)
}


