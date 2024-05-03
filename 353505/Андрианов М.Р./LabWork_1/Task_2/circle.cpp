#include "circle.h"

Circle::Circle() {
    radius = 100;
    massCenter = QPointF(480, 270);
    PrintInfo();
}

void Circle::draw(QPainter &painter)
{
    painter.setBrush(Qt::red);
    painter.setPen(Qt::black);
    painter.drawEllipse(massCenter, radius, radius);
}

void Circle::deltaRotation(qreal)
{}

void Circle::deltaScale(qreal scale, qreal deltascale)
{

    radius *= ((scale + deltascale)/scale);
}

void Circle::deltaShift(QPointF shift)
{
    massCenter += shift;
}

void Circle::updateArea()
{
    area = PI * radius * radius;
}

void Circle::updatePerimetr()
{
    perimetr = 2 * PI * radius;
}

void Circle::updateMassCenter()
{

}
