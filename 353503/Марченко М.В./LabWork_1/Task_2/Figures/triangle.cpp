#include "triangle.h"
#include <QPainter>

Triangle::Triangle(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Triangle::~Triangle()
{

}

long double Triangle::GetArea()
{
    return qAbs(startPoint().x()-endPoint().x()) * qAbs(startPoint().y() - endPoint().y())/2;
}

long double Triangle::GetPerimeter()
{
    long double dx = qAbs(startPoint().x() - endPoint().x());
    long double dy = qAbs(startPoint().y() - endPoint().y());

    return dx + sqrt(dy*dy + dx*dx);
}

// Реализуем метод отрисовки
void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), startPoint().y())
                << QPointF((endPoint().x() > startPoint().x()) ? endPoint().x() : startPoint().x(),
                           endPoint().y())
                << QPointF((endPoint().x() > startPoint().x()) ? startPoint().x() : endPoint().x(),
                           endPoint().y());

    painter->drawPolygon(polygon);

    //Вычисление центра масс определяется нахождения среднего арифметического по x и y соответственно
    painter->setPen(QPen(Qt::red, 2));
    m_centerPoint = QPointF((startPoint().x() + endPoint().x() +
                             startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)* qAbs(endPoint().x() - startPoint().x())/2)/3,
                            (startPoint().y() + 2 * endPoint().y())/ 3);
    painter->drawPoint(m_centerPoint);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
