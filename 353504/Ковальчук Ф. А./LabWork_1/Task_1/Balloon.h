#ifndef BALLOON_H
#define BALLOON_H

#include <QWidget>
#include <QPainter>
#include <QDebug>

#include "MovingEllipse.h"

class Balloon : public MovingEllipse, public QWidget{
public:
    Balloon() = default;
    void Move();
    void Draw(QPainter* painter);

private:
    int m_lineStartX = m_posX + m_width / 2;
    int m_lineStartY = m_posY + 220;
    int m_lineEndX = m_posX + m_width / 2;
    int m_lineEndY = m_posY + 400;

    int m_rectX = m_posX + m_width / 2 - 15;
    int m_rectY = m_posY + 210;

    float m_ballonBaseRotation = 0;
    float m_deltaRotation = 0.02f;
    int m_offsetY = 0;
};

#endif // BALLOON_H
