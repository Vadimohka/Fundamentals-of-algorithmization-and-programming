#include "ring.h"

QColor colors[] {Qt::black,Qt::gray,Qt::lightGray,Qt::darkMagenta,Qt::darkBlue,Qt::blue,Qt::green,Qt::yellow,Qt::magenta,Qt::red};

Ring::Ring(int num, int road)
    : num(num)
{
    color = colors[num-1];
    width = 20 * (12-num);
    height = 30;
    x_pos = 215 + (road-1)*400 - width/2;
    y_pos = 670 - (num-1)*30;
}
