#include "star8.h"
#include <QPainter>

Star8::Star8(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Star8::~Star8()
{

}

long double Star8::GetArea()
{
    long double dx = qAbs(startPoint().x() - endPoint().x());
    long double outerR = dx / 2;
    long double innerR = outerR/(2*cos(M_PI/8));
    return 4 * innerR * outerR * sin(M_PI/8);
}

long double Star8::GetPerimeter()
{
    return qAbs(startPoint().x() - endPoint().x())/(4*cos(M_PI/8)) * 16;
}

// Реализуем метод отрисовки
void Star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    const int centerX = (startPoint().x() + endPoint().x()) / 2;
    const int centerY = (startPoint().y() + endPoint().y()) / 2;
    const int outerRadius = abs(endPoint().x() - startPoint().x()) / 2; //внешний радиус
    const int innerRadius = outerRadius/(2*cos(M_PI/8));  // внутрненний радиус, по совместительству длина стороны

    const int numPoints = 8;
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

