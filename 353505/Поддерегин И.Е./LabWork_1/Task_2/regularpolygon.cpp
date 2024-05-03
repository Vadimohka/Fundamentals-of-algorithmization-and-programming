#include <QPainter>
#include "regularpolygon.h"

RegularPolygon::RegularPolygon(QPointF point, QObject *parent)
    : Shape(point, parent)
{
    Q_UNUSED(point);
}

RegularPolygon::~RegularPolygon()
{

}


qreal RegularPolygon::square()
{
    return m_square;
}

qreal RegularPolygon::perimeter()
{
    return m_perimeter;
}


void RegularPolygon::setPerimeter(QVector<QPointF> points)
{
    m_perimeter = 0;
    for (int i = 0; i < points.size() - 1; ++i)
    {
        m_perimeter += QLineF(points[i], points[i+1]).length();
    }
}

void RegularPolygon::setSquare()
{
    m_square = m_radius.x() * m_radius.y() * m_vertexCount * sin(2 * PI / m_vertexCount) / 2;
}

void RegularPolygon::setVertexCount(int vertexCount)
{
    m_vertexCount = vertexCount;
}


void RegularPolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    m_radius = QPointF(abs((startPoint().x() - endPoint().x()) / 2),
                       abs((startPoint().y() - endPoint().y()) / 2));

    m_angleIncrement = 2 * PI / m_vertexCount;

    setTransformOriginPoint(centerPoint());

    painter->setPen(QPen(Qt::black, 2));

    QVector<QPointF> points;

    qreal minX = fmin(startPoint().x(), endPoint().x());
    qreal minY = fmin(startPoint().y(), endPoint().y());


    for (int i = 0; i < m_vertexCount; ++i)
    {
        points.append(QPointF(minX + m_radius.x() * cos(i * m_angleIncrement) + m_radius.x(),
                              minY + m_radius.y() * sin(i * m_angleIncrement) + m_radius.y()));
    }
    this->setPerimeter(points);
    this->setSquare();

    painter->drawPolygon(points.data(), points.size());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
