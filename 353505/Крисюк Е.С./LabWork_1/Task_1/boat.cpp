#include "boat.h"


Boat::Boat()  {
    Rect_1 = new Move_Rect();
    Rect_1 -> Set_Rect();

    Rect_2 = new QGraphicsRectItem(-10,-130,20,130);

    QPolygon pol;
    pol << QPoint(-130,0) << QPoint(130,0) << QPoint(70,60) << QPoint(-70,60);

    Polygon = new QGraphicsPolygonItem(pol);

}

void Boat::Move_Up()  {
    int height = 0;
    QTimer* timer = new QTimer(this);
    timer->setInterval(21);

    connect(timer, &QTimer::timeout, this, [=]()  mutable{
        if(height <= 60){
            ++height;
            Rect_1 -> setRect(10, -120, 100, height);
        }
        Rect_1 -> Move_Down(-1);

        if (Rect_1 -> y() <= 0) {
            timer -> stop();
        }
    });

    timer->start();

}
void Boat::Move_Down() {
    int height = 60;
    QTimer* timer = new QTimer(this);
    timer->setInterval(21);

    connect(timer, &QTimer::timeout, this, [=]() mutable{
        Rect_1->Move_Down(1);

        if (Rect_1 -> y() >= 60) {
            if(height <= 0){
                timer -> stop();
            }
            --height;
            Rect_1 -> setRect(10, -120, 100, height);
        }
    });

    timer->start();

}
