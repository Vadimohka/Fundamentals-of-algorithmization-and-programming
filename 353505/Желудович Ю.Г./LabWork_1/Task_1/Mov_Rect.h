#ifndef MOV_RECT_H
#define MOV_RECT_H

#include <QGraphicsRectItem>
#include <QObject>

class Mov_Rect: public QGraphicsRectItem, public QObject{


public:
    void Set_Rect();
    void Move_Up(qreal, qreal);
    void Move_Down(qreal, qreal);

private:

};

#endif // MOV_RECT_H
