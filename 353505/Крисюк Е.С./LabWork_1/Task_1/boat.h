#ifndef BOARD_H
#define BOARD_H

#include "./move_rect.h"
#include <QGraphicsPolygonItem>
#include <QTimer>


class Boat : public Move_Rect
{

public:
    Move_Rect* Rect_1;
    QTimer* timer;
    QGraphicsRectItem* Rect_2;
    QGraphicsPolygonItem* Polygon;

public:
    Boat();
    void Move_Up();
    void Move_Down();



private:


};

#endif // BOARD_H
