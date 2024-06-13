#include "diamond.h"

diamond::diamond() {}

diamond::~diamond()
{

}

void diamond::initialization()
{
    area = (w * h) / 2;
    now_area = area;
    perimeter = 4 * sqrt(pow(w / 2, 2) + pow(h / 2, 2));
    now_perimeter = perimeter;
}

QRectF diamond::boundingRect() const
{
    return QRectF(-w/2-40, -h/2-40, w+60, h+60);
}

void diamond::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(hasFocus() ? QPen(QColor(252, 15, 192), 3) : QPen(QColor(138, 43, 226), 3));
    painter->drawPoint(0, 0);
    painter->setPen(QPen(QColor(R, G, B), PenSize));

    QPointF top(QPointF(0, -h / 2 * now_size));
    QPointF right(QPointF(w / 2 * now_size, 0));
    QPointF bottom(QPointF(0, h / 2 * now_size));
    QPointF left(QPointF(-w / 2 * now_size, 0));

    rhombus << top << right << bottom << left << top;
    painter->drawPolygon(rhombus);

    QThread::msleep(5);

    double delta = ang - now_ang;
    now_ang += delta / 10;

    double deltaSize = size - now_size;
    now_size += deltaSize / 10;

    now_area = area * pow(now_size, 2);
    now_perimeter = perimeter * now_size;

    this->setRotation(now_ang);
    this->setScale(now_size);

    if (this->hasFocus())
        Output();

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
