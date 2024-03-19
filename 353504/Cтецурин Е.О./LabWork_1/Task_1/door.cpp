#include "door.h"
#include <QPainter>

Door::Door(QWidget *parent) :  MovingRectangle(parent)
{
    setFixedSize(200, 350);
    isOpen =false;
}


void Door::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    int flagWidth = 200;
    int flagHeight = 350;
    QRect flagRect(0, 0, flagWidth, flagHeight);

    painter.fillRect(flagRect, Qt::darkRed);
}

void Door::toggle()
{
    isOpen=!isOpen;
}

