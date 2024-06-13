#include "Dump_truck.h"

Dump_Truck::Dump_Truck()
{
    Rect_1 = new Mov_Rect();
    Rect_1 -> Set_Rect();

    Rect_2 = new QGraphicsRectItem(960, 255, 130, 225);

    Rect_3 = new QGraphicsRectItem(710, 375, 250, 105);

    Light_2 = new QGraphicsEllipseItem(1065, 405, 20, 20);

    Window = new QGraphicsRectItem(1030, 275, 60, 50);

    Wheel_1 = new QGraphicsEllipseItem(740, 430, 100, 100);

    Wheel_2 = new QGraphicsEllipseItem(965, 430, 100, 100);

    road = new QGraphicsRectItem(0, 405, 1571, 406);

    sky = new QGraphicsRectItem(0, 0, 1571, 405);

    sun = new QGraphicsEllipseItem(1350, 50, 100, 100);

    Disk_1 = new QGraphicsEllipseItem(765, 455, 50, 50);

    Disk_2 = new QGraphicsEllipseItem(990, 455, 50, 50);

}

void Dump_Truck::Move_Up() {
    QPointF rotationPoint(710, 375); // Координаты точки вращения
        Rect_1 -> setTransformOriginPoint(rotationPoint);

        qreal angle = 0;

        QTimer* timer = new QTimer(this);
        timer -> setInterval(41);

        connect(timer, &QTimer::timeout, this, [=]() mutable{
        if(angle >= -60) {
        Rect_1 -> setRotation(angle);
            angle--;
}
        else{
            timer->stop();
        }
        });

        timer -> start();

}

void Dump_Truck::Move_Down() {
    QPointF rotationPoint(710, 375); // Координаты точки вращения
        Rect_1 -> setTransformOriginPoint(rotationPoint);

        qreal angle = -60;

        QTimer* timer = new QTimer(this);
        timer -> setInterval(41);


        connect(timer, &QTimer::timeout, this, [=]() mutable{
        if(angle <= 0) {
        Rect_1 -> setRotation(angle);
            angle++;
}
        else{
            timer->stop();
        }
        });

        timer -> start();
        }

