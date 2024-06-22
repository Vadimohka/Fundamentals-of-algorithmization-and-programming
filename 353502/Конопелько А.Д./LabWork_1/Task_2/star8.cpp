#include "star8.h"

Star8::Star8(QObject *parent)
{

}

qreal Star8::findPerimeter()
{
    return 16 * sqrt(100 * 100 + 50 * 50 - 2 * 50 * 100 * cos(M_PI / 16));
}

qreal Star8::findSquare()
{
    return 16 * 100 * 50 * sin(M_PI / 16);
}

void Star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i = 0; i <= 15; i++){
        if(i % 2 == 0)
            points[i] = QPoint(cos(6.28 * i / 16) * 100, sin(6.28 * i / 16) * 100);
        else
            points[i] = QPoint(cos(6.28 * i / 16) * 50, sin(6.28 * i / 16) * 50);
    }
    QPolygon pol;
    pol << QPoint(points[0]) << QPoint(points[1]) << QPoint(points[2]) <<
        QPoint(points[3]) << QPoint(points[4]) << QPoint(points[5]) <<
        QPoint(points[6]) << QPoint(points[7])<< QPoint(points[8]) <<
        QPoint(points[9]) << QPoint(points[10]) << QPoint(points[11]) <<
        QPoint(points[12]) << QPoint(points[13]) <<
        QPoint(points[14]) << QPoint(points[15]);
    painter -> drawPolygon(pol);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Star8::~Star8()
{

}
