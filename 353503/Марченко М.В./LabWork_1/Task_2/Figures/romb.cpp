#include "romb.h"
#include <QPainter>

Romb::Romb(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Romb::~Romb()
{

}

long double Romb::GetArea()
{
    return qAbs(startPoint().x() - endPoint().x()) * qAbs(startPoint().y() - endPoint().y())/2;
}

long double Romb::GetPerimeter()
{
    return 2 * sqrt(powl(qAbs(startPoint().x() - endPoint().x()), 2) + powl(qAbs(startPoint().y() - endPoint().y()), 2));
}

// Реализуем метод отрисовки
void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), startPoint().y())
                << QPointF(endPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1)*
                           abs((endPoint().y() - startPoint().y())/2))
                << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), endPoint().y())
                << QPointF(startPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1)*
                           abs((endPoint().y() - startPoint().y())/2));

    painter->drawPolygon(polygon);

    painter->setPen(QPen(Qt::red, 2));
    m_centerPoint = QPointF(endPoint().x() > startPoint().x() ? qAbs(startPoint().x() - endPoint().x())/2 + startPoint().x() : qAbs(startPoint().x() - endPoint().x())/2 + endPoint().x(),
                            endPoint().y() > startPoint().y() ? qAbs(startPoint().y() - endPoint().y())/2 + startPoint().y() : qAbs(startPoint().y() - endPoint().y())/2 + endPoint().y());
    painter->drawPoint(m_centerPoint);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
