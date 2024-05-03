#include "star8.h"

star8::star8(QPointF point, QObject *parent) : shape(point,parent)
{}

QRectF star8::boundingRect() const
{
    qreal side = qMax(qAbs(finalPoint.x() - getStartPoint().x()), qAbs(finalPoint.y() - getStartPoint().y()));
    return QRectF(startPoint.x()-side,startPoint.y()-side,side*2,side*2);
}

void star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(color, 4/scaleFactor));

    Q_UNUSED(option);
    Q_UNUSED(widget);

    /*perim = ;
    square = ;*/

    QPolygonF polygon;
    double betweenPoint = sqrt((finalPoint.x() - getStartPoint().x()) * (finalPoint.x() - getStartPoint().x()) +
                               (finalPoint.y() - getStartPoint().y()) * (finalPoint.y() - getStartPoint().y()));

    perim = 6 * betweenPoint;

    square = 1.5 * betweenPoint * betweenPoint * sqrt(3);

    qreal side = qMax(qAbs(finalPoint.x() - getStartPoint().x()), qAbs(finalPoint.y() - getStartPoint().y()));

    QPolygonF star;
    for (int i = 0; i < 16; ++i) {
        qreal radius = (i % 2 == 0) ? side : side / 2.0;
        polygon << QPointF(getStartPoint().x() + radius * cos(2 * M_PI * i / 16 - M_PI/2),
                        getStartPoint().y() + radius * sin(2 * M_PI * i / 16 - M_PI/2));
    }

    center = startPoint;

    painter->drawPolygon(polygon);
}
