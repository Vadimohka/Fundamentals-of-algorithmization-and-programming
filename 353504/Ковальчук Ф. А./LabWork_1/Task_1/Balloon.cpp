#include "Balloon.h"


void Balloon::Move(){
    if(m_posY < 500){
        if(rand()% 3 >= 1) MoveXY(1, -1);
        else MoveXY(-1, -1);
    }
    if(m_ballonBaseRotation < -1){
        m_deltaRotation = 0.02f;
    }
    if(m_ballonBaseRotation > 1){
        m_deltaRotation = -0.02f;
    }

    if(m_lineStartY > 696) m_lineStartY = 696;
    if(m_lineEndY > 696) m_lineEndY = 696;

    if(rand() % 2 == 0 && m_offsetY < 300){
        m_lineStartY += 1;
        m_lineEndY += 1;
        m_rectY += 1;
        m_offsetY += 1;
        m_ballonBaseRotation += m_deltaRotation;
    }
}
void Balloon::Draw(QPainter* painter){
    painter->setBrush(QBrush(Qt::red));
    painter->rotate(m_ballonBaseRotation);
    painter->drawLine(m_lineStartX, m_lineStartY, m_lineEndX, m_lineEndY);
    painter->drawRect(m_rectX, m_rectY, 30, 20);
    painter->rotate(-m_ballonBaseRotation);
    painter->drawEllipse(m_posX, m_posY, m_width, m_height);

}
