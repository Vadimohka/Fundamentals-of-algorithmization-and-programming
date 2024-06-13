#include "circle.h"
#include <QPainter>

Circle::Circle(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Circle::~Circle() {}

long double Circle::GetArea()
{
    return pow(qAbs(startPoint().x() - endPoint().x())/2.,2) * M_PI;
}

long double Circle::GetPerimeter()
{
    return qAbs(startPoint().x() - endPoint().x()) * M_PI;
}

// Реализуем метод отрисовки
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().x() - startPoint().x()));

    painter->drawEllipse(rect); // Используем drawEllipse для рисования круга

    painter->setPen(QPen(Qt::red, 2));
    m_centerPoint = rect.center();
    painter->drawPoint(m_centerPoint);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}



