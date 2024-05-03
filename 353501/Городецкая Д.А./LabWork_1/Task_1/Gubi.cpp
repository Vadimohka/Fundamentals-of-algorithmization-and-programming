#include "Gubi.h"
#include <QPainter>
#include <QPushButton>
#include <QTimer>
#include <qgraphicsitem.h>

Gubi::Gubi(QGraphicsObject *parent) : Ellipse() {
  tim2 = new QTimer();
  connect(tim2, &QTimer::timeout, this, &Gubi::moveMouse);
  y = 0;
  stop2 = true;
  tim2->start(1000 / 20);
}

Gubi::~Gubi() {
  tim2->stop();
  delete tim2;
}

void Gubi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
  painter->setBrush(Qt::red);
  painter->drawEllipse(25, -y + 80, 40, 20);
  painter->drawEllipse(25, y + 90, 40, 20);
}

void Gubi::moveMouse() {
  if (y < pup && stop2 == false) {

    y += 1;
    update();
    if (y == pup) {
      up = true;
    }
  } else if (y >= pstop2 && up == true) {

    y -= 1;
    update();
    stop2 = true;
  } else {
    // tim2->stop();
  }
}
void Gubi::onTime2() {
  stop2 = false;
  up = false;
}
