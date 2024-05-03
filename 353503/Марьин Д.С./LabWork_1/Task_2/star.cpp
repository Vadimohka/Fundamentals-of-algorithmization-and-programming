#include "star.h"
long double areaOfTriangleFormedByPoints(const QPointF& p1, const QPointF& p2, const QPointF& p3)
{
    return p1.x() * (p2.y() - p3.y()) + p2.x() * (p3.y() - p1.y()) + p3.x() * (p1.y() - p2.y());
}
Star::Star(): Shape()
{}

void Star::setPoints(QVector<QPointF> points)
{
    temp = points;
    QLineF line = QLineF(points.at(0), points.at(1));
    radius = line.length();
    center = temp.at(0);
    c = temp.at(0);
    QPointF x = QPointF(temp.at(0).x(),temp.at(0).y());
    out = QPoint(x.x() + radius * cos(rotation ), x.y() + radius * sin(rotation));
    small = radius * (sin(M_PI * (0.5 - 1.0 / starType)) - cos(M_PI * (0.5 - 1.0 / starType)) * sin(2 * M_PI / starType) / (1 + cos(2 * M_PI / starType)));
    inner = QPoint(x.x() + small * cos((0.5) * angle + rotation), x.y() + small * sin((0.5) * angle + rotation));
    rect = QRectF(c.x() - radius,c.x() - radius,2*radius,2*radius);
}

void Star::setStarType(int type)
{
    starType = type;
    angle = 2 * M_PI/starType;
}

long double Star::square()
{
    S = starType * 2 * areaOfTriangleFormedByPoints(c,inner,out);
    return S;
}
long double Star::perimetr()
{
    return starType * 2 * QLineF(inner,out).length();
}
qreal Star::getSpecificParam_1()
{
    return radius;
}

void Star::setSpecificParam_1(qreal t)
{
    rect = QRectF(rect.center().x() - t,rect.center().y() - t,2*t,2*t);
    temp.last().setX(temp.last().x() - (radius - t));
    radius = t;
    this->setPoints(temp);
    update();
}

QRectF Star::boundingRect() const
{
    return QRectF(temp.at(0).x() - radius,temp.at(0).y() - radius,2*radius,2*radius);
}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPolygon polygon;

    QPointF x = QPointF(temp.at(0).x(),temp.at(0).y());
    for (int i = 0; i < starType; ++i)
    {
        polygon << QPoint(x.x() + radius * cos(i * angle + rotation ), x.y() + radius * sin(i * angle + rotation));
        polygon << QPoint(x.x() + small * cos((i + 0.5) * angle + rotation), x.y() + small * sin((i + 0.5) * angle + rotation));
    }
    QPen pen = QPen(this->getColor());
    pen.setCosmetic(true);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setBrush(this->getBrush());
    painter->drawPolygon(polygon);

}
