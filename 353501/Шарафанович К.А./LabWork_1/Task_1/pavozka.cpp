#include "pavozka.h"

pavozka::pavozka():object()
{

    Rwheel=new QGraphicsEllipseItem (-20,50,40,40,this);
    Rwheel->setBrush(Qt::red);
    Lwheel=new QGraphicsEllipseItem (80,50,40,40,this);
    orange1 = new QGraphicsEllipseItem(-15,-90,50,50,this);
    orange2 = new QGraphicsEllipseItem(60,-90,50,50,this);
    orange2 -> setBrush(Qt::green);
    orange3 = new QGraphicsEllipseItem(23,-125,50,50,this);
    orange1 -> setBrush(Qt::green);
    orange3 -> setBrush(Qt::green);
    Lwheel->setBrush(Qt::red);
    timer = new QTimer(this);
    timer -> setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveWheels()));
    timer->start();


 }


void pavozka::moveWheels() {
   // Двигаем колеса вправо
  Rwheel -> setTransformOriginPoint(0,70);
  Rwheel->setRotation(rotation);
  rotation +=1;
  Lwheel -> setTransformOriginPoint(100,70);
  Lwheel->setRotation(rotation);
  rotation +=1;
   // Обновляем отображение
   update();
}
