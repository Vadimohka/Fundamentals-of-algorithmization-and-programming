#include "star6.h"
#include <QPainter>

Star6::Star6(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Star6::~Star6()
{

}

long double Star6::GetArea()
{
    return 3 * pow(qAbs(startPoint().x() - endPoint().x())/(2 * sqrt(3)),2) * sqrt(3);
}

long double Star6::GetPerimeter()
{
    return qAbs(startPoint().x() - endPoint().x())/(2 * sqrt(3)) * 12;
}

// Реализуем метод отрисовки
void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    const int centerX = (startPoint().x() + endPoint().x()) / 2;
    const int centerY = (startPoint().y() + endPoint().y()) / 2;
    const int outerRadius = abs(endPoint().x() - startPoint().x()) / 2; //внешний радиус
    const int innerRadius = outerRadius/sqrt(3);  // внутрненний радиус, по совместительству длина стороны

    const double angleIncrement = M_PI / 6;
    const double startAngle = -M_PI / 2;  // Начальный угол поворота

    QPolygonF star;
    for (int i = 0; i < 12; ++i)
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
