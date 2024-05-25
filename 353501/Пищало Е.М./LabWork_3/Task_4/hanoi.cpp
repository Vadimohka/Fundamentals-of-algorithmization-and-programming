#include "hanoi.h"

hanoi::hanoi() {}


void hanoi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);

    // Draw the three towers
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawRect(-305, 30, 10, 250 - 10);
    painter->drawRect(-5, 30, 10, 250 - 10);
    painter->drawRect(295, 30, 10, 250 - 10);

    painter->drawRect(-430, 250, 260, 25);
    painter->drawRect(-130, 250, 260, 25);
    painter->drawRect(+170, 250, 260, 25);

    for(int i = 10 - n;i < 10;++i){
        if(disk_unused[i]){
            disk_pos[i].setX(TowerX[0] - diskWidth[i] / 2);
            disk_pos[i].setY(250 - (i + 1) * diskHeight);
            disk_unused[i] = false;
        }

        painter->setBrush(Qt::gray);
        painter->setPen(Qt::gray);
        painter->drawRect(disk_pos[i].x(),disk_pos[i].y() + posN[n - 1],diskWidth[i],diskHeight);
    }

    if (isChanging) {
        lastEmptyPositionA = 230 - n * diskHeight;
    }
}


QRectF hanoi::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void hanoi::changeNumberOfRings(int arg)
{
    n = arg;
    update();
}

void hanoi::getn(int num)
{
    n = num;
    update();
}
void hanoi::animate(int num, char from, char to)
{
    int i = num;

    // Up
    if (!on_positionY[i])
    {
        if (disk_pos[i].y() > posMinN[n - 1])
        {
            disk_pos[i].setY(disk_pos[i].y() - 3);
        }
        else
        {
            on_PositionX[i] = true;
        }
    }

    /////////////////////////////////////////// A -> B
    if (from == 'A' && to == 'B')
    {
        if (on_PositionX[i])
        {
            if (disk_pos[i].x() < 0 - diskWidth[i] / 2)
            {
                disk_pos[i].setX(disk_pos[i].x() + 3);
            }
            else
            {
                on_PositionX[i] = false;
                on_positionY[i] = true;
            }
        }
        // Down
        if (on_positionY[i])
        {
            if (disk_pos[i].y() < lastEmptyPositionB)
            {
                disk_pos[i].setY(disk_pos[i].y() + 3);
            }
            else
            {
                lastEmptyPositionB -= 20;
                on_positionY[i] = false;
                finished = true;
            }
        }
    }

    /////////////////////////////////////////// A -> C
    if (from == 'A' && to == 'C')
    {
        if (on_PositionX[i])
        {
            if (disk_pos[i].x() < 300 - diskWidth[i] / 2)
            {
                disk_pos[i].setX(disk_pos[i].x() + 3);
            }
            else
            {
                on_PositionX[i] = false;
                on_positionY[i] = true;
            }
        }
        // Down
        if (on_positionY[i])
        {
            if (disk_pos[i].y() < lastEmptyPositionC)
            {
                disk_pos[i].setY(disk_pos[i].y() + 3);
            }
            else
            {
                lastEmptyPositionC -= 20;
                on_positionY[i] = false;
                finished = true;
            }
        }
    }

    /////////////////////////////////////////// B -> A
    if (from == 'B' && to == 'A')
    {
        if (on_PositionX[i])
        {
            if (disk_pos[i].x() > -300 - diskWidth[i] / 2)
            {
                disk_pos[i].setX(disk_pos[i].x() - 3);
            }
            else
            {
                on_PositionX[i] = false;
                on_positionY[i] = true;
            }
        }
        // Down
        if (on_positionY[i])
        {
            if (disk_pos[i].y() < lastEmptyPositionA)
            {
                disk_pos[i].setY(disk_pos[i].y() + 3);
            }
            else
            {
                lastEmptyPositionA -= 20;
                on_positionY[i] = false;
                finished = true;
            }
        }
    }

    /////////////////////////////////////////// B -> C
    if (from == 'B' && to == 'C')
    {
        if (on_PositionX[i])
        {
            if (disk_pos[i].x() < 300 - diskWidth[i] / 2)
            {
                disk_pos[i].setX(disk_pos[i].x() + 3);
            }
            else
            {
                on_PositionX[i] = false;
                on_positionY[i] = true;
            }
        }
        // Down
        if (on_positionY[i])
        {
            if (disk_pos[i].y() < lastEmptyPositionC)
            {
                disk_pos[i].setY(disk_pos[i].y() + 3);
            }
            else
            {
                lastEmptyPositionC -= 20;
                on_positionY[i] = false;
                finished = true;
            }
        }
    }

    /////////////////////////////////////////// C -> A
    if (from == 'C' && to == 'A')
    {
        if (on_PositionX[i])
        {
            if (disk_pos[i].x() > -300 - diskWidth[i] / 2)
            {
                disk_pos[i].setX(disk_pos[i].x() - 3);
            }
            else
            {
                on_PositionX[i] = false;
                on_positionY[i] = true;
            }
        }
        // Down
        if (on_positionY[i])
        {
            if (disk_pos[i].y() < lastEmptyPositionA)
            {
                disk_pos[i].setY(disk_pos[i].y() + 3);
            }
            else
            {
                lastEmptyPositionA -= 20;
                on_positionY[i] = false;
                finished = true;
            }
        }
    }
    /////////////////////////////////////////// C -> B
    if (from == 'C' && to == 'B')
    {
        if (on_PositionX[i])
        {
            if (disk_pos[i].x() > 0 - diskWidth[i] / 2)
            {
                disk_pos[i].setX(disk_pos[i].x() - 3);
            }
            else
            {
                on_PositionX[i] = false;
                on_positionY[i] = true;
            }
        }
        // Down
        if (on_positionY[i])
        {
            if (disk_pos[i].y() < lastEmptyPositionB)
            {
                disk_pos[i].setY(disk_pos[i].y() + 3);
            }
            else
            {
                lastEmptyPositionB -= 20;
                on_positionY[i] = false;
                finished = true;
            }
        }
    }
    update();
}
