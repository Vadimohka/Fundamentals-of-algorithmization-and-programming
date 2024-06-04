#ifndef RING_H
#define RING_H

#include<QPainter>
#include <QWidget>

class Ring
{
public:
    Ring(int num, int road);
    void x_pos_incr(int x){x_pos += x;};
    void y_pos_incr(int y){y_pos += y;};
    int X(){return x_pos;};
    int Y(){return y_pos;};
    int Width(){return width;};
    QColor getColor(){return color;};
    QRect get_rect(){return QRect(x_pos, y_pos, width, height);}
private:
    QColor color;
    int num;
    int x_pos;
    int y_pos;
    int height;
    int width;
};

#endif // RING_H
