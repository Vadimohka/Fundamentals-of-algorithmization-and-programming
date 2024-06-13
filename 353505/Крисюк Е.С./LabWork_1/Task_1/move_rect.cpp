#include "move_rect.h"

void Move_Rect::Set_Rect(){
    setRect(10, -120, 100, 60);

}

void Move_Rect::Move_Up(qreal y) {
    moveBy(0, y);

}

void Move_Rect::Move_Down(qreal y) {
    moveBy(0, y);
}
