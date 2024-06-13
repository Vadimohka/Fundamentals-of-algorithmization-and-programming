#include "flagg.h"


void flagg::draw(QPainter& painter)
{
    QBrush brush;
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(brush);

    painter.drawRect(x,y,width/5,height/3*3);

    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(brush);

    painter.drawRect(x+width/5,y,width/5*4,height/3*2);

    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);

    painter.setBrush(brush);

    painter.drawRect(x+width/5,y+height/3*2,width/5*4,height/3);
}
