#include "star5.h"

Star5::Star5(QObject *parent)
{

}

qreal Star5::findPerimeter()
{
    return 10 * sqrt(100 * 100 + 50 * 50 - 2 * 50 * 100 * cos(M_PI / 10));
}

qreal Star5::findSquare()
{
    return 10 * 100 * 50 * sin(M_PI / 10);
}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i = 0; i <= 9; i++){
        if(i % 2 == 0)
            points[i] = QPoint(cos(2 * M_PI * i / 10) * 100, sin(2 * M_PI * i / 10) * 100);
        else
            points[i] = QPoint(cos(2 * M_PI * i / 10) * 50, sin(2 * M_PI * i / 10) * 50);
    }
    QPolygon pol;
    pol << QPoint(points[0]) << QPoint(points[1]) << QPoint(points[2]) <<
        QPoint(points[3])  << QPoint(points[4]) << QPoint(points[5]) <<
        QPoint(points[6]) << QPoint(points[7])<< QPoint(points[8]) <<
        QPoint(points[9]);
    painter -> drawPolygon(pol);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Star5::~Star5()
{

}
