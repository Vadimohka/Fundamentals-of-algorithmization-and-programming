#include "arrow.h"
#include <QPainter>

Arrow::Arrow(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Arrow::~Arrow()
{

}

long double Arrow::GetArea()
{
    return powl(qAbs(startPoint().x() - endPoint().x()), 2)/3.;
}

long double Arrow::GetPerimeter()
{
    return qAbs(startPoint().x() - endPoint().x())*(31+sqrt(481))/15.;
}

// Реализуем метод отрисовки
void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    qreal dx = endPoint().x() - startPoint().x();

    QPolygonF arrow;

    arrow << QPointF(startPoint().x(), startPoint().y()- dx/5)
          << QPointF(startPoint().x()+ dx / 2, startPoint().y()-dx/5)
          << QPointF(startPoint().x() + dx / 2, startPoint().y() - 8*dx/15)
          << QPointF(startPoint().x() + dx, startPoint().y())
          << QPointF(startPoint().x() + dx / 2, startPoint().y() +8* dx/15 )
          << QPointF(startPoint().x()+ dx / 2, startPoint().y() + dx /5)
          << QPointF(startPoint().x(), startPoint().y() + dx / 5);

    painter->drawPolygon(arrow);

    painter->setPen(QPen(Qt::red, 2));
    m_centerPoint = QPointF((startPoint().x() * 2 + 4*(startPoint().x() + dx/2) + startPoint().x()+dx)/7, startPoint().y());
    painter->drawPoint(m_centerPoint);

    Q_UNUSED(option)
    Q_UNUSED(widget)

}

