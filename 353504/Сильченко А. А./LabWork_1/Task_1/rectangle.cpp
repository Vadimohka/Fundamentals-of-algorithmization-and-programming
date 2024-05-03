#include "rectangle.h"
#include <QPainter>

void Rectangle::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    draw(&painter);
}

void Rectangle::draw(QPainter *painter)
{
     painter->setBrush(QBrush(Qt::cyan, Qt::SolidPattern));
    painter->drawRect(300, 300, 100, 200);
}

void Rectangle::ride()
{

}

bool Rectangle::dr(int sch)
{
    if(s<=0&&!be)
        s=sch, be=1;
    if(s==0&&be)
        be=0;
    return s==0;
}
