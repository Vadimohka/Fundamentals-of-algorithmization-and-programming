#ifndef MOVE_RECT_H
#define MOVE_RECT_H

#include <QGraphicsRectItem>
#include <QObject>

class Move_Rect: public QGraphicsRectItem, public QObject{


public:
    void Set_Rect();
    void Move_Up(qreal);
    void Move_Down(qreal);

private:

};

#endif // MOVE_RECT_H
