#include "square.h"
#include <QPainter>

Square::Square(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Square::~Square()
{

}

long double Square::GetArea()
{
    return powl(qAbs(startPoint().x() - endPoint().x()), 2);
}

long double Square::GetPerimeter()
{
    return qAbs(startPoint().x() - endPoint().x())*4;
}

// Реализуем метод отрисовки
void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().x() - startPoint().x()));

    painter->drawRect(rect);

    painter->setPen(QPen(Qt::red, 2));
    m_centerPoint = QPointF(qAbs(endPoint().x() - startPoint().x())/2 + (endPoint().x() > startPoint().x() ? startPoint().x(): endPoint().x()),
                             qAbs(endPoint().x() - startPoint().x())/2 + (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()));
    painter->drawPoint(m_centerPoint);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

