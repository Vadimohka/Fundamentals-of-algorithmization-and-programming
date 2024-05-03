#include "circle.h"

Circle::Circle(QPointF point) : Shape(point){}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 4));

    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());
    qreal side = width < heigh ? width : heigh;

    square = 3.14 * width * width / 4;
    perimetr = 3.14 * width;

    QRectF rect((GetEndPoint().x() > GetStarterPoint().x() ? GetStarterPoint().x() : GetEndPoint().x()),
                (GetEndPoint().y() > GetStarterPoint().y() ? GetStarterPoint().y() : GetEndPoint().y()),
                side, side);

    painter->drawEllipse(rect);
}

qreal Circle::GetSquare()
{
    return square;
}

qreal Circle::GetPerimetr()
{
    return perimetr;
}

QPointF Circle::GetCenter()
{
    center = {boundingRect().center().x(), boundingRect().center().y()};
    return center;
}
