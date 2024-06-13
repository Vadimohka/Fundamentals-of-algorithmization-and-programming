#include "hexagon.h"
#include <QPainter>

Hexagon::Hexagon(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Hexagon::~Hexagon()
{

}

long double Hexagon::GetArea()
{
    return 3* powl(qAbs(startPoint().x() - endPoint().x())/2.,2) * sqrt(3)/2.;
}

long double Hexagon::GetPerimeter()
{
    return qAbs(startPoint().x() - endPoint().x()) * 3;
}

// Реализуем метод отрисовки
void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    const int centerX = (startPoint().x() + endPoint().x()) / 2;
    const int centerY = (startPoint().y() + endPoint().y()) / 2;
    const int radius = abs(endPoint().x() - startPoint().x()) / 2;
    const double angleIncrement = M_PI / 3;  // Угол между вершинами шестиугольника
    const double startAngle = -M_PI / 2;  // Начальный угол поворота

    QPolygonF polygon;
    for (int i = 0; i < 6; ++i)
    {
        double angle = startAngle + i * angleIncrement;
        int x = centerX + radius * cos(angle);
        int y = centerY + radius * sin(angle);
        polygon << QPointF(x, y);
    }

    painter->drawPolygon(polygon);

    painter->setPen(QPen(Qt::red, 2));
    m_centerPoint = QPointF(endPoint().x() > startPoint().x() ? qAbs(startPoint().x() - endPoint().x())/2 + startPoint().x() : qAbs(startPoint().x() - endPoint().x())/2 + endPoint().x(),
                            endPoint().y() > startPoint().y() ? qAbs(startPoint().y() - endPoint().y())/2 + startPoint().y() : qAbs(startPoint().y() - endPoint().y())/2 + endPoint().y());
    painter->drawPoint(m_centerPoint);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

