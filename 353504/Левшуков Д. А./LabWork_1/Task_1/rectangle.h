#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<QPainter>

class rectangle
{
public:
    rectangle();
    void DrawRec(QPainter *);
    void move(int k);
protected:
    qreal x;
    int k;
    const int w=200,h=50,y=200;
};

#endif // RECTANGLE_H
