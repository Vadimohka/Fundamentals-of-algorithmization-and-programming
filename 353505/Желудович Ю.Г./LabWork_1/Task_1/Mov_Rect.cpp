#include "Mov_Rect.h"

void Mov_Rect::Set_Rect(){
    setRect(705, 285, 250, 90);
}

void Mov_Rect::Move_Up(qreal x, qreal y) {
    moveBy(x, y);
}

void Mov_Rect::Move_Down(qreal x, qreal y) {
    moveBy(x, y);
}
