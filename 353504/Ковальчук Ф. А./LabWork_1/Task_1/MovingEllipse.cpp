#include "MovingEllipse.h"


MovingEllipse::MovingEllipse(){
    m_posX = (800 / 2) - (m_width / 2);
    m_posY = (700 / 2) - (m_height / 2) - 80;
}
void MovingEllipse::MoveXY(int x,int y){
    m_posX += x;
    m_posY += y;
}
