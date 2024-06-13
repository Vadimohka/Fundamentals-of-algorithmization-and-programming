#ifndef DUMP_TRUCK_H
#define DUMP_TRUCK_H

#include "Mov_Rect.h"
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QTransform>


class Dump_Truck : public Mov_Rect
{

public:
    Mov_Rect* Rect_1;
    QGraphicsRectItem* Rect_2;
    QGraphicsRectItem* Rect_3;
    QGraphicsEllipseItem* Light_2;
    QGraphicsRectItem* Window;
    QGraphicsEllipseItem* Wheel_1;
    QGraphicsEllipseItem* Wheel_2;
    QGraphicsRectItem* road;
    QGraphicsRectItem* sky;
    QGraphicsEllipseItem* sun;
    QGraphicsEllipseItem* Disk_1;
    QGraphicsEllipseItem* Disk_2;
    QBrush* color;

public:
    Dump_Truck();
    void Move_Up();
    void Move_Down();

private:

};

#endif // DUMP_TRUCK_H
