#include "ellipse.h"

Ellipse::Ellipse(QPointF point) : Shape(point){}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 4));

    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());

    square = abs((GetEndPoint().x() - GetStarterPoint().x()) * (GetEndPoint().y() - GetStarterPoint().y()));
    perimetr = (abs(GetEndPoint().x() - GetStarterPoint().x()) + abs(GetEndPoint().y() - GetStarterPoint().y())) * 2;

    QRectF ellipse((GetEndPoint().x() > GetStarterPoint().x() ? GetStarterPoint().x() : GetEndPoint().x()),
                (GetEndPoint().y() > GetStarterPoint().y() ? GetStarterPoint().y() : GetEndPoint().y()),
                width, heigh);

    painter->drawEllipse(ellipse);
}

qreal Ellipse::GetSquare()
{
    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());

    return (width * heigh * 0.785);
}

qreal Ellipse::GetPerimetr()
{
    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());

    perimetr = (width + heigh) * 2;

    return perimetr;
}

QPointF Ellipse::GetCenter()
{
    center = {boundingRect().center().x(), boundingRect().center().y()};
    return center;
}
