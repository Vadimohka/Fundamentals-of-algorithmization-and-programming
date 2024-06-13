#include "movingellipse.h"

MovingEllipse::MovingEllipse(QObject *parent)
    : QObject(parent), QGraphicsItem()
{

}

MovingEllipse::~MovingEllipse()
{}

void MovingEllipse::MoveEllipse()
{
   static int contl = 0;
   static int contr = 0;

    if (contl != 20) {
        setPos(contl,0);
        contl +=10;
    }
    else  {
      if (contr != 40) {
            setPos(contl-contr,0);
            contr +=10;
        }
        else {
            contl = 0;
            contr = 0;
        }
    }
}

