#include "eyes.h"

Eyes::Eyes(QObject *parent)
    : MovingEllipse{parent}
{
    timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(MoveEllipse()));
}

void Eyes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(110,125,50,50);
    painter->drawEllipse(270,125,50,50);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}


/* Переопределив метод перехвата события нажатия кнопки мыши,
 * добавляем посылку СИГНАЛА от объекта
 * */
void Eyes::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

    if(timer->isActive()){
        timer->stop();
    }
    else{
        timer->start(200);
    }
}

