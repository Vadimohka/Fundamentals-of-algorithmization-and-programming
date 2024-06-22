#include "triangle.h"

Triangle::Triangle(QObject *parent) {

}

qreal Triangle::findPerimeter()
{
    return 25 * 1.3 * (sqrt(17) + sqrt(20) + sqrt(29));
}

qreal Triangle::findSquare()
{
    return 18 * 625 * 1.3 * 1.3 / 2;
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    points[0] = QPoint(-50 * 1.3, -50 * 1.3);
    points[1] = QPoint(75 * 1.3, 0);
    points[2] = QPoint(-25 * 1.3, 50 * 1.3);
    QPolygon pol;
    pol << QPoint(points[0]) << QPoint(points[1]) << QPoint(points[2]);
    painter -> drawPolygon(pol);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Triangle::~Triangle()
{

}
