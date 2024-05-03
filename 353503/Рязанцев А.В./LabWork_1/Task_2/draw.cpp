#include "draw.h"

Draw::Draw(QPointF point) : Shape(point){}

void Draw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF Poligon;

    painter->setPen(QPen(Qt::white, 4));

    Poligon << GetStarterPoint();
    Poligon << GetEndPoint();

    painter->drawPolygon(Poligon);

    perimetr = (GetEndPoint().x() - GetStarterPoint().x()) * (GetEndPoint().x() - GetStarterPoint().x()) +
               (GetEndPoint().y() - GetStarterPoint().y()) * (GetEndPoint().y() - GetStarterPoint().y());
    square = perimetr;
}

qreal Draw::GetSquare()
{
    return square;
}

qreal Draw::GetPerimetr()
{
    return perimetr;
}

QPointF Draw::GetCenter()
{
    center = {boundingRect().center().x(), boundingRect().center().y()};
    return center;
}
