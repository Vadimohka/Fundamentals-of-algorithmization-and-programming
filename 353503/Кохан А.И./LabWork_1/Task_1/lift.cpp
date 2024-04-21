#include "lift.h"

#define x_Lift 418
#define y_Lift 595
#define w_Lift 90
#define h_Lift 115

lift::lift() : QGraphicsItem(){}

void lift::paint(QPainter *painter, const QStyleOptionGraphicsItem *opinion, QWidget *widget)
{
    Q_UNUSED(opinion);
    Q_UNUSED(widget);
    painter->drawRect(0, 0, 981, 741);

    QPen p_door;
    p_door.setWidth(1);
    QBrush b_door;

    painter->setPen(p_door);
    painter->setBrush(QColor(239, 208, 174));

    painter->drawRect(400, 95, 130, 630);

    p_door.setWidth(3);

    painter->setBrush(QColor(0, 0, 0));
    painter->setPen(p_door);

    painter->drawLine(x_Lift + 10, 50, x_Lift + 10, 715);
    painter->drawLine(x_Lift + 80, 50, x_Lift + 80, 715);

    p_door.setWidth(10);
    b_door.setColor(Qt::darkGray);
    b_door.setStyle(Qt::SolidPattern);

    painter->setPen(p_door);
    painter->setBrush(b_door);

    painter->drawRect(x_Lift, y_Lift, w_Lift, h_Lift);

    p_door.setWidth(1);
    p_door.setColor(Qt::white);
    b_door.setStyle(Qt::NoBrush);

    painter->setPen(p_door);
    painter->setBrush(b_door);

    painter->drawLine(x_Lift + 45, y_Lift + 6, x_Lift + 45, y_Lift + 109); //Щёлка лифта

}

QRectF lift::boundingRect() const
{
    return QRectF(x_Lift - 5, y_Lift - 5, w_Lift + 10, h_Lift + 10);
}
