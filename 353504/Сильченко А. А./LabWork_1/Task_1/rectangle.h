#ifndef RECTANGLE_H
#define RECTANGLE_H
#pragma once
#include <QWidget>

class Rectangle:public QWidget
{
public:
    int x=200;
    void paintEvent(QPaintEvent *);
    void draw(QPainter *painter);
    void ride();
    bool dr(int sch);
private:
    int m=1;
    int s=-1;
    bool be=0;
};

#endif // RECTANGLE_H
