#include "star6.h"

star6::star6() {}

star6::~star6()
{

}

void star6::initialization()
{
    area = 3 * sqrt(3) * (h*h - w*w);
    now_area = area;
    perimeter = 6 * (h + w);
    now_perimeter = perimeter;
}

void star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(hasFocus() ? QPen(QColor(252, 15, 192), 3) : QPen(QColor(138, 43, 226), 3));
    painter->drawPoint(0, 0);

    outerRadius = h;
    innerRadius = w;
    alpha = (2 * M_PI) / 6.0;
    shiftAngle = -M_PI / 2.0;

    for (int i = 0; i < 6; ++i)
    {
        outerX = std::cos(i * alpha + shiftAngle) * outerRadius;
        outerY = std::sin(i * alpha + shiftAngle) * outerRadius;
        innerX = std::cos((i * alpha) + alpha / 2.0 + shiftAngle) * innerRadius;
        innerY = std::sin((i * alpha) + alpha / 2.0 + shiftAngle) * innerRadius;

        starPoints.append(QPointF(outerX, outerY));
        starPoints.append(QPointF(innerX, innerY));
    }

    painter->setPen(QPen(QColor(R, G, B), PenSize));
    painter->drawPolygon(starPoints);

    QThread::msleep(5);

    double delta = ang - now_ang;
    now_ang += delta / 10;

    double deltaSize = size - now_size;
    now_size += deltaSize / 10;

    now_area = area * now_size * now_size;
    now_perimeter = perimeter * now_size;

    this->setRotation(now_ang);
    this->setScale(now_size);

    if (this->hasFocus())
        Output();

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

