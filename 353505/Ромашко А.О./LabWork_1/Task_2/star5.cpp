#include "star5.h"
#include <QPainter>
#include "cmath"

Star5::Star5(QPointF point, QObject *parent) :
    BasicFigure(point,parent)
{
    Q_UNUSED(point)
}

Star5::~Star5()
{

}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

double Star5::area() {
    double side = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));
    return abs(0.3125 * side * side * sqrt(5 * (5 + 2 * sqrt(5))));
}

double Star5::perimeter() {
    double side = qMax(qAbs(endPoint().x() - startPoint().x()), qAbs(endPoint().y() - startPoint().y()));
    return abs(5 * side);
}
