#include "mouth.h"

Mouth::Mouth(QObject *parent)
    : MovingEllipse{parent}
{
    timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(MoveEllipse()));
}

void Mouth::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen(QColor(208, 20, 9), 3);
    painter->setPen(pen);

    painter->setBrush(QColor(255, 52, 38));
    painter->drawEllipse(160,250,120,40);
    painter->drawLine(160, 270, 280, 270);

}


/* Переопределив метод перехвата события нажатия кнопки мыши,
  добавляем посылку СИГНАЛА от объекта */
void Mouth::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    if(timer->isActive()){
        timer->stop();
    }
    else{
        timer->start(100);
    }
}

void Mouth::MoveEllipse()
{
  if (ClosedMouth) {
      if (opacity > 0.001)  {
      opacity -= 0.1;
      setOpacity(opacity);
      }
      else {
      timer->stop();
      ClosedMouth = false;
      }
  }

  if (not ClosedMouth) {
      if (opacity < 0.99)  {
          opacity += 0.1;
      setOpacity(opacity);
    }
  else  {
     timer->stop();
      ClosedMouth = true;
    }
  }
}

