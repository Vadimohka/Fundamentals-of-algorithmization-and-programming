#ifndef CAR_H
#define CAR_H
#include "rectangle.h"

class Car:public Rectangle
{
public:
    Car();

    bool opened=false, lighton=false, changed=false;
    void paintEvent(QPaintEvent *);
    void drawCar(QPainter *painter);
    void drawLight(QPainter *painter);
    void drawDoors(QPainter *painter);
    void open();
    void light();
    bool door();
    int get_mov();
 private:
    int r=0;
    int mov=0;
    double y1=0;
};

#endif // CAR_H
