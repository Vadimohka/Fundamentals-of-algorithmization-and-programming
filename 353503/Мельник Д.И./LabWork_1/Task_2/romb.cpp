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

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

double Romb::area()
{
    // Вычисляем длины диагоналей
    double d1 = abs(endPoint().x() - startPoint().x());
    double d2 = abs(endPoint().y() - startPoint().y());

    // Площадь ромба равна половине произведения диагоналей
    qDebug () << 0.5 * d1 * d2;
    return 0.5 * d1 * d2;
}

double Romb::perimeter()
{
    // Вычисляем длины диагоналей
    double d1 = abs(endPoint().x() - startPoint().x());
    double d2 = abs(endPoint().y() - startPoint().y());

    // Периметр ромба равен четырем квадратным корням из суммы квадратов половин диагоналей
    qDebug () << 4 * sqrt((0.5 * d1) * (0.5 * d1) + (0.5 * d2) * (0.5 * d2));
    return 4 * sqrt((0.5 * d1) * (0.5 * d1) + (0.5 * d2) * (0.5 * d2));
}
