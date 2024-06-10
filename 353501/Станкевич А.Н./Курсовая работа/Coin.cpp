#include "Coin.h"

Coin::Coin(QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    /* Устанавливаем улчай номер цвета яблока
     * */
    color = qrand() % ((3 + 1) - 1) + 1;
}

Coin::~Coin()
{

}

QRectF Coin::boundingRect() const
{
    return QRectF(-20,-20,40,40);   // Ограничиваем область, в которой лежит яблоко
}

void Coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPainterPath path(QPointF(0,-10));
    path.cubicTo(0,-10, -5,-14,  -12,-8);
    path.cubicTo(-12,-8, -20,12, -10,15);
    path.cubicTo(-10,15, -5,20, 0,16);
    path.cubicTo(0,16, 5,25, 10,15);
    path.cubicTo(10,15, 20,13, 12,-8);
    path.cubicTo(15,-8, 5,-14,  0,-10);
    painter->setBrush(Qt::yellow);
    painter->drawPath(path);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}
