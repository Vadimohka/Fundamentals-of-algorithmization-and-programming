#include "quadrate.h"

Quadrate::Quadrate(QObject *parent)
{

}

qreal Quadrate::findPerimeter()
{
    return 200 * 4 / sqrt(2);
}

qreal Quadrate::findSquare()
{
    return 200 * 100;
}

void Quadrate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i = 0; i <= 3; i++){
        points[i] = QPoint(cos(2 * M_PI * i / 4 + M_PI / 4) * 100, sin(2 * M_PI * i / 4 + M_PI / 4) * 100);
    }
    QPolygon pol;
    pol << QPoint(points[0]) << QPoint(points[1]) << QPoint(points[2]) <<
        QPoint(points[3]);
    painter -> drawPolygon(pol);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Quadrate::~Quadrate()
{

}
