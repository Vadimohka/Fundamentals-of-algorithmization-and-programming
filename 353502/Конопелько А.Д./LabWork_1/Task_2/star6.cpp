#include "star6.h"

Star6::Star6(QObject *parent)
{

}

qreal Star6::findPerimeter()
{
    return 12 * sqrt(100 * 100 + 50 * 50 - 2 * 50 * 100 * cos(M_PI / 12));
}

qreal Star6::findSquare()
{
    return 12 * 100 * 50 * sin(M_PI / 12);
}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i = 0; i <= 11; i++){
        if(i % 2 == 0)
            points[i] = QPoint(cos(6.28 * i / 12) * 100, sin(6.28 * i / 12) * 100);
        else
            points[i] = QPoint(cos(6.28 * i / 12) * 50, sin(6.28 * i / 12) * 50);
    }
    QPolygon pol;
    pol << QPoint(points[0]) << QPoint(points[1]) << QPoint(points[2]) <<
        QPoint(points[3]) << QPoint(points[4]) << QPoint(points[5]) <<
        QPoint(points[6]) << QPoint(points[7])<< QPoint(points[8]) <<
        QPoint(points[9]) << QPoint(points[10]) << QPoint(points[11]);
    painter -> drawPolygon(pol);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Star6::~Star6()
{

}
