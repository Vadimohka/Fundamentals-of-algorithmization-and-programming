#ifndef RECTUNGLE_H
#define RECTUNGLE_H

#include "base.h"
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>


class rectungle:public base
{
public:
    rectungle();
    void draw(QGraphicsScene *scene, int width, int height, int a, int &h)override;
    //void centerMasse(QGraphicsScene *scene, int &x, int &y)override;
    void perSquareMasse(int width, int height, int a)override;
    void getParametrs(int &side1, int &side2, int &side3, int a) override;

private:
};

#endif // RECTUNGLE_H
