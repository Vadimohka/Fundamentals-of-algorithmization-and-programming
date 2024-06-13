#include "star5.h"
#include <QPainter>

Star5::Star5(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Star5::~Star5()
{

}

long double Star5::GetArea()
{
    long double dx = qAbs(startPoint().x() - endPoint().x());
    long double R = dx/2;
    long double r = dx/4;
    return 5 * R * r * sin(M_PI/5);
}

long double Star5::GetPerimeter()
{
    return 10 * qAbs(startPoint().x() - endPoint().x())/2 * sqrt(5-4*cos(M_PI/5));
}

// Реализуем метод отрисовки
void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    const int centerX = (startPoint().x() + endPoint().x()) / 2;
    const int centerY = (startPoint().y() + endPoint().y()) / 2;
    const int outerRadius = abs(endPoint().x() - startPoint().x()) / 2;
    const int innerRadius = outerRadius / 2;

    const int numPoints = 5;  // Количество вершин звезды
    const double angleIncrement = 2 * M_PI / (numPoints * 2);
    const double startAngle = -M_PI / 2;  // Начальный угол поворота

    QPolygonF star;
    for (int i = 0; i < numPoints * 2; ++i)
    {
        double angle = startAngle + i * angleIncrement;
        int radius = (i % 2 == 0) ? outerRadius : innerRadius;
        int x = centerX + radius * cos(angle);
        int y = centerY + radius * sin(angle);
        star << QPointF(x, y);
    }

    painter->drawPolygon(star);

    painter->setPen(QPen(Qt::red, 2));
    m_centerPoint = QPointF(endPoint().x() > startPoint().x() ? qAbs(startPoint().x() - endPoint().x())/2 + startPoint().x() : qAbs(startPoint().x() - endPoint().x())/2 + endPoint().x(),
                            endPoint().y() > startPoint().y() ? qAbs(startPoint().y() - endPoint().y())/2 + startPoint().y() : qAbs(startPoint().y() - endPoint().y())/2 + endPoint().y());
    painter->drawPoint(m_centerPoint);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

