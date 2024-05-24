#include "star_5.h"
#include <QPainter>
#include "cmath"

Star_5::Star_5(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Star_5::~Star_5()
{

}

// Реализуем метод отрисовки
void Star_5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    qreal side = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));

    QPolygonF star;
    for (int i = 0; i < 10; ++i) {
        // Добавляем точки для внешних и внутренних вершин звезды
        qreal radius = (i % 2 == 0) ? side : side / 2.0;
        star << QPointF(startPoint().x() + radius * cos(2 * M_PI * i / 10 - M_PI/2),
                        startPoint().y() + radius * sin(2 * M_PI * i / 10 - M_PI/2));
    }
    painter->drawPolygon(star);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

double Star_5::area() {
    double side = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));
    return abs(0.3125 * side * side * sqrt(5 * (5 + 2 * sqrt(5))));
}

double Star_5::perimeter() {
    double side = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));
    return abs(5 * side);
}
