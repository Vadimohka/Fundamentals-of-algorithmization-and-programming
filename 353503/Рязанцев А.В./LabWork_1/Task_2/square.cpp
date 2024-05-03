#include "square.h"

Square::Square(QPointF point) : Shape(point) {}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 4));

    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());
    qreal side = fmin(width, heigh);

    square = side * side;
    perimetr = side * 4;

    QRectF rect((GetEndPoint().x() > GetStarterPoint().x() ? GetStarterPoint().x() : GetEndPoint().x()),
                (GetEndPoint().y() > GetStarterPoint().y() ? GetStarterPoint().y() : GetEndPoint().y()),
                side - 5, side - 5);

    painter->drawRect(rect);
}

qreal Square::GetSquare()
{
    return square;
}

qreal Square::GetPerimetr()
{
    return perimetr;
}

QPointF Square::GetCenter()
{
    center = {boundingRect().center().x(), boundingRect().center().y()};
    return center;
}

