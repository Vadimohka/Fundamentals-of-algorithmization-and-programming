#include "towerwidget.h"
#include <QColor>
#include <QBrush>

towers::towers()
{

}

void towers::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);

    painter->setBrush(Qt::white);
    painter->drawRect(-305, 30, 10, 250 - 10);
    painter->drawRect(-5, 30, 10, 250 - 10);
    painter->drawRect(295, 30, 10, 250 - 10);

    painter->drawRect(-430, 250, 260, 25);
    painter->drawRect(-130, 250, 260, 25);
    painter->drawRect(+170, 250, 260, 25);

    for (int i = 10 - n; i < 10; ++i)
    {
        if (diskUnused[i])
        {
            position[i].setX(towerNum[0] - width[i] / 2);
            position[i].setY(250 - (i + 1) * height);
            diskUnused[i] = false;
        }

        painter->setBrush(QColor(255, 8, 94));
        painter->setPen(Qt::black);
        painter->drawRect(position[i].x(), position[i].y() + posN[n - 1], width[i], height);
    }


    if (change)
    {
        lastPositionA = 230 - n * (height);
    }
}

QRectF towers::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void towers::changeNumberOfRings(int arg)
{
    n = arg;
    change = true;
    update();
}

void towers::getn(int num)
{
    n = num;
    update();
}


void towers::animate(int num, int from, int to)
{
    int i = num;

    // Up
    if (!positionY[i])
    {
        if (position[i].y() > minPositionNum[n - 1])
        {
            position[i].setY(position[i].y() - 5);
        }
        else
        {
            positionX[i] = true;
        }
    }

    if (from == 0 && to == 1)
    {
        if (positionX[i])
        {
            if (position[i].x() < 0 - width[i] / 2)
            {
                position[i].setX(position[i].x() + 5);
            }
            else
            {
                positionX[i] = false;
                positionY[i] = true;
            }
        }
        // Down
        if (positionY[i])
        {
            if (position[i].y() < lastPositionB)
            {
                position[i].setY(position[i].y() + 5);
            }
            else
            {
                lastPositionB -= 20;
                positionY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 0 && to == 2)
    {
        if (positionX[i])
        {
            if (position[i].x() < 300 - width[i] / 2)
            {
                position[i].setX(position[i].x() + 5);
            }
            else
            {
                positionX[i] = false;
                positionY[i] = true;
            }
        }
        // Down
        if (positionY[i])
        {
            if (position[i].y() < lastPositionC)
            {
                position[i].setY(position[i].y() + 5);
            }
            else
            {
                lastPositionC -= 20;
                positionY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 1 && to == 0)
    {
        if (positionX[i])
        {
            if (position[i].x() > -300 - width[i] / 2)
            {
                position[i].setX(position[i].x() - 5);
            }
            else
            {
                positionX[i] = false;
                positionY[i] = true;
            }
        }
        // Down
        if (positionY[i])
        {
            if (position[i].y() < lastPositionA)
            {
                position[i].setY(position[i].y() + 5);
            }
            else
            {
                lastPositionA -= 20;
                positionY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 1 && to == 2)
    {
        if (positionX[i])
        {
            if (position[i].x() < 300 - width[i] / 2)
            {
                position[i].setX(position[i].x() + 5);
            }
            else
            {
                positionX[i] = false;
                positionY[i] = true;
            }
        }
        // Down
        if (positionY[i])
        {
            if (position[i].y() < lastPositionC)
            {
                position[i].setY(position[i].y() + 5);
            }
            else
            {
                lastPositionC -= 20;
                positionY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 2 && to == 0)
    {
        if (positionX[i])
        {
            if (position[i].x() > -300 - width[i] / 2)
            {
                position[i].setX(position[i].x() - 5);
            }
            else
            {
                positionX[i] = false;
                positionY[i] = true;
            }
        }
        // Down
        if (positionY[i])
        {
            if (position[i].y() < lastPositionA)
            {
                position[i].setY(position[i].y() + 5);
            }
            else
            {
                lastPositionA -= 20;
                positionY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 2 && to == 1)
    {
        if (positionX[i])
        {
            if (position[i].x() > 0 - width[i] / 2)
            {
                position[i].setX(position[i].x() - 5);
            }
            else
            {
                positionX[i] = false;
                positionY[i] = true;
            }
        }
        // Down
        if (positionY[i])
        {
            if (position[i].y() < lastPositionB)
            {
                position[i].setY(position[i].y() + 5);
            }
            else
            {
                lastPositionB -= 20;
                positionY[i] = false;
                finished = true;
            }
        }
    }
    update();
}

void towers::update()
{
    prepareGeometryChange();
    QGraphicsItem::update();
}

int towers::getN() const{
    return n;
}
