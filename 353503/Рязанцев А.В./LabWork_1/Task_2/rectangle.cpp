#include "rectangle.h"

#include <QPainter>

Rectangle::Rectangle(QPointF point) : Shape(point){
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 4));
    //painter->setPen();

    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());

    square = abs((GetEndPoint().x() - GetStarterPoint().x()) * (GetEndPoint().y() - GetStarterPoint().y()));
    perimetr = (abs(GetEndPoint().x() - GetStarterPoint().x()) + abs(GetEndPoint().y() - GetStarterPoint().y())) * 2;

    QRectF rect((GetEndPoint().x() > GetStarterPoint().x() ? GetStarterPoint().x() : GetEndPoint().x()),
                (GetEndPoint().y() > GetStarterPoint().y() ? GetStarterPoint().y() : GetEndPoint().y()),
                width, heigh);

    painter->drawRect(rect);
}

qreal Rectangle::GetSquare()
{
    return square;
}

qreal Rectangle::GetPerimetr()
{
    return perimetr;
}

QPointF Rectangle::GetCenter()
{
    center = {boundingRect().center().x(), boundingRect().center().y()};
    return center;
}
