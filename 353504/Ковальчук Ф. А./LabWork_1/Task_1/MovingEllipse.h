#ifndef MOVINGELLIPSE_H
#define MOVINGELLIPSE_H

class MovingEllipse{
public:
    MovingEllipse();
    void MoveXY(int x,int y);

public:
    const int m_width = 190;
    const int m_height = 215;

    int m_posX = 0;
    int m_posY = 0;
};

#endif // MOVINGELLIPSE_H
