#include "rectangle.h"
#include <QPainter>

Rectangle::Rectangle(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Rectangle::~Rectangle()
{

}

long double Rectangle::GetArea()
{
    return qAbs(startPoint().x() - endPoint().x()) *  qAbs(startPoint().y() - endPoint().y());
}

long double Rectangle::GetPerimeter()
{
    return (qAbs(startPoint().x() - endPoint().x()) +  qAbs(startPoint().y() - endPoint().y()))*2;
}

// Реализуем метод отрисовки
void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));

    painter->drawRect(rect);

    //Отображение центра масс
    painter->setPen(QPen(Qt::red, 2));
    m_centerPoint = QPointF(endPoint().x() > startPoint().x() ? qAbs(startPoint().x() - endPoint().x())/2 + startPoint().x() : qAbs(startPoint().x() - endPoint().x())/2 + endPoint().x(),
                            endPoint().y() > startPoint().y() ? qAbs(startPoint().y() - endPoint().y())/2 + startPoint().y() : qAbs(startPoint().y() - endPoint().y())/2 + endPoint().y());
    painter->drawPoint(m_centerPoint);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
