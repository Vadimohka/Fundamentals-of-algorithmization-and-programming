#include "truck.h"

Truck::Truck(QGraphicsObject *parent) : MoveableRect(parent)
{
    back = new MoveableRect(0, -50, 140, 50, QColor(250, 128, 114), this);

    back->setPos(-28, 0);
    back->setTransformOriginPoint(124, 0);

    mult = 0.5;
    sign = 1;

    points[0] = QPoint(-95, 25);
    points[1] = QPoint(-95, 10);
    points[2] = QPoint(-90, 10);
    points[3] = QPoint(-90, -20);
    points[4] = QPoint(-65, -45);
    points[5] = QPoint(-35, -45);
    points[6] = QPoint(-35, 0);
    points[7] = QPoint(95, 0);
    points[8] = QPoint(95, 25);

    wheel1 = QRect(-68, 15, 36, 36);
    wheel2 = QRect(8, 15, 36, 36);
    wheel3 = QRect(48, 15, 36, 36);

    rim1 = QRect(-60, 23, 20, 20);
    rim2 = QRect(16, 23, 20, 20);
    rim3 = QRect(56, 23, 20, 20);

    base << points[0] << points[1] << points[2] << points[3] << points[4] << points[5] << points[6] << points[7] << points[8];
    window << QPoint(-85, -20) << QPoint (-65, -40) << QPoint(-40, -40) << QPoint(-40, -20);
    door = QRect(-85, -20, 45, 30);
}

QRectF Truck::boundingRect() const
{
    return QRectF(-150, -200, 300, 300);
}

void Truck::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QColor color(238, 24, 24);

    painter->setBrush(color);
    painter->drawPolygon(base);

    QBrush brush1(Qt::black);
    painter->setBrush(brush1);
    painter->drawEllipse(wheel1);
    painter->drawEllipse(wheel2);
    painter->drawEllipse(wheel3);

    brush1 = QBrush(Qt::gray);
    painter->setBrush(brush1);
    painter->drawEllipse(rim1);
    painter->drawEllipse(rim2);
    painter->drawEllipse(rim3);

    color = QColor(135, 206, 250);

    painter->setBrush(color);
    painter->drawPolygon(window);

    color = QColor(200, 24, 24);
    painter->setBrush(color);
    painter->drawRect(door);
}

void Truck::rotate()
{
    angle += mult * sign;

    if (angle >= 0 && angle <= 90)
    {
        back->setRotation(angle);
    }
    else if (angle < 0) angle = 0;
    else angle = 90;

    back->update();
}

