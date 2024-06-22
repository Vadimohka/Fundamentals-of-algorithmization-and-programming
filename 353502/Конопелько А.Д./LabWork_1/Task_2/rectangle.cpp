#include "rectangle.h"

Rectangle::Rectangle(QObject *parent){

}

qreal Rectangle::findPerimeter()
{
    return 140 * 2 + 80 * 2;
}

qreal Rectangle::findSquare()
{
    return 140 * 80;
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    points[0] = QPoint(70, -40);
    points[1] = QPoint(70, 40);
    points[2] = QPoint(-70, 40);
    points[3] = QPoint(-70, -40);
    QPolygon pol;
    pol << QPoint(points[0]) << QPoint(points[1]) << QPoint(points[2]) <<
        QPoint(points[3]);
    painter -> drawPolygon(pol);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Rectangle::~Rectangle()
{

}
