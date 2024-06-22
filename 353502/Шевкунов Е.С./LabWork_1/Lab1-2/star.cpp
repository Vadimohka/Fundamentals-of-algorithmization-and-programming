#include "star.h"


Star::Star(QWidget *parent)
    : Figure(parent)
{}

Star::Star(const QVector<QPoint> &pv, short n, QPair<short, short> ID, QColor brush, QWidget *parent)
    : Figure (parent)
{
    this->ID = ID;
    center = pv.at(0);
    this->setPos(center);

    length = dist(pv.at(0), pv.at(1));
    minilength = qAbs(length * (sin(PI * (1.0 / 2 - 1.0 / n)) - cos(PI * (1.0 / 2 - 1.0 / n)) * sin(2 * PI / n) / (1 + cos(2 * PI / n))));

    amnt = n;
    short i;

    for (i = 0; i < amnt; ++i)
    {
        points.push_back(QPointF(length  * sin((qreal) i * 2 * PI / amnt),
                                 length  * cos((qreal) i * 2 * PI / amnt)));

        inner_points.push_back(QPointF(minilength * sin((qreal) i * 2 * PI / amnt + PI / amnt),
                                       minilength * cos((qreal) i * 2 * PI / amnt + PI / amnt)));
    }

    for (i = 0; i < amnt; ++i)
    {
        all_points.push_back(points.at(i));
        all_points.push_back(inner_points.at(i));
    }

    former_pos = this->QGraphicsItem::pos();
    former_rotation = this->rotation();
    former_scale = this->QGraphicsItem::scale();

    brush_color = brush;
}


//**********************************************


QPointF Star::getCenter()
{
    return this->QGraphicsItem::pos();
}

qreal Star::getSquare()
{
    qreal square = triangleSquare(points.at(0),
                                  inner_points.at(amnt - 1),
                                  inner_points.at(0));;
    for (short i = 1; i < amnt; ++i)
    {
        square += triangleSquare(points.at(i),
                                 inner_points.at(i - 1),
                                 inner_points.at(i));
    }
    square += polygonSquare(inner_points.data(), amnt);

    return square * this->QGraphicsItem::scale() * this->QGraphicsItem::scale();
}

qreal Star::getPerimeter()
{
    qreal perimeter = 0;
    for (short i = 0; i < amnt; ++i)
    {
        perimeter += dist(points.at(i), inner_points.at(i));
    }

    return perimeter * this->QGraphicsItem::scale();
}


//**********************************************


QPair<int, int> Star::getParameter()
{
    return QPair<int, int>(length, 0);
}

void Star::setParameter(QPair<int, int> input)
{
    length = input.first;
    minilength = qAbs(length * (sin(PI * (1.0 / 2 - 1.0 / amnt)) - cos(PI * (1.0 / 2 - 1.0 / amnt)) * sin(2 * PI / amnt) / (1 + cos(2 * PI / amnt))));


    points.clear();
    inner_points.clear();
    all_points.clear();

    short i;

    for (i = 0; i < amnt; ++i)
    {
        points.push_back(QPointF(length  * sin((qreal) i * 2 * PI / amnt),
                                 length  * cos((qreal) i * 2 * PI / amnt)));

        inner_points.push_back(QPointF(minilength * sin((qreal) i * 2 * PI / amnt + PI / amnt),
                                       minilength * cos((qreal) i * 2 * PI / amnt + PI / amnt)));
    }

    for (i = 0; i < amnt; ++i)
    {
        all_points.push_back(points.at(i));
        all_points.push_back(inner_points.at(i));
    }
}


//**********************************************


QRectF Star::boundingRect() const
{
    return QRectF(-length - 1, - length - 1, 2 * length + 1, 2 * length + 1);
}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen ((is_selected ? Qt::blue : Qt::black), 2 / this->QGraphicsItem::scale());
    painter->setPen(pen);
    painter->setBrush(brush_color);

    painter->drawPolygon(all_points.data(), 2 * amnt);
}
