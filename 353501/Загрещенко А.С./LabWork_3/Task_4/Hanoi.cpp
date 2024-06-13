#include "towerOfHanoi.h"

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
            DiskPosition[i].setX(TowerX[0] - diskWidth[i] / 2);
            DiskPosition[i].setY(250 - (i + 1) * diskHeight);
            diskUnused[i] = false;
        }
      
        painter->setBrush(Qt::white);
        painter->setPen(Qt::black);
        painter->drawRect(DiskPosition[i].x(), DiskPosition[i].y() + posN[n - 1], diskWidth[i], diskHeight);
    }

   
    if (isChanging)
    {
        lastEmptyPositionA = 230 - n * (diskHeight);
    }
}

QRectF towers::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void towers::changeNumberOfRings(int arg)
{
    n = arg;
    isChanging = true;
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
    if (!PositionY[i])
    {
        if (DiskPosition[i].y() > MinpositionN[n - 1])
        {
            DiskPosition[i].setY(DiskPosition[i].y() - 5);
        }
        else
        {
            PositionX[i] = true;
        }
    }

    /////////////////////////////////////////// A -> B
    if (from == 0 && to == 1)
    {
        if (PositionX[i])
        {
            if (DiskPosition[i].x() < 0 - diskWidth[i] / 2)
            {
                DiskPosition[i].setX(DiskPosition[i].x() + 5);
            }
            else
            {
                PositionX[i] = false;
                PositionY[i] = true;
            }
        }
        // Down
        if (PositionY[i])
        {
            if (DiskPosition[i].y() < lastEmptyPositionB)
            {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else
            {
                lastEmptyPositionB -= 20;
                PositionY[i] = false;
                finished = true;
            }
        }
    }

    /////////////////////////////////////////// A -> C
    if (from == 0 && to == 2)
    {
        if (PositionX[i])
        {
            if (DiskPosition[i].x() < 300 - diskWidth[i] / 2)
            {
                DiskPosition[i].setX(DiskPosition[i].x() + 5);
            }
            else
            {
                PositionX[i] = false;
                PositionY[i] = true;
            }
        }
        // Down
        if (PositionY[i])
        {
            if (DiskPosition[i].y() < lastEmptyPositionC)
            {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else
            {
                lastEmptyPositionC -= 20;
                PositionY[i] = false;
                finished = true;
            }
        }
    }

    /////////////////////////////////////////// B -> A
    if (from == 1 && to == 0)
    {
        if (PositionX[i])
        {
            if (DiskPosition[i].x() > -300 - diskWidth[i] / 2)
            {
                DiskPosition[i].setX(DiskPosition[i].x() - 5);
            }
            else
            {
                PositionX[i] = false;
                PositionY[i] = true;
            }
        }
        // Down
        if (PositionY[i])
        {
            if (DiskPosition[i].y() < lastEmptyPositionA)
            {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else
            {
                lastEmptyPositionA -= 20;
                PositionY[i] = false;
                finished = true;
            }
        }
    }

    /////////////////////////////////////////// B -> C
    if (from == 1 && to == 2)
    {
        if (PositionX[i])
        {
            if (DiskPosition[i].x() < 300 - diskWidth[i] / 2)
            {
                DiskPosition[i].setX(DiskPosition[i].x() + 5);
            }
            else
            {
                PositionX[i] = false;
                PositionY[i] = true;
            }
        }
        // Down
        if (PositionY[i])
        {
            if (DiskPosition[i].y() < lastEmptyPositionC)
            {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else
            {
                lastEmptyPositionC -= 20;
                PositionY[i] = false;
                finished = true;
            }
        }
    }

    /////////////////////////////////////////// C -> A
    if (from == 2 && to == 0)
    {
        if (PositionX[i])
        {
            if (DiskPosition[i].x() > -300 - diskWidth[i] / 2)
            {
                DiskPosition[i].setX(DiskPosition[i].x() - 5);
            }
            else
            {
                PositionX[i] = false;
                PositionY[i] = true;
            }
        }
        // Down
        if (PositionY[i])
        {
            if (DiskPosition[i].y() < lastEmptyPositionA)
            {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else
            {
                lastEmptyPositionA -= 20;
                PositionY[i] = false;
                finished = true;
            }
        }
    }
    /////////////////////////////////////////// C -> B
    if (from == 2 && to == 1)
    {
        if (PositionX[i])
        {
            if (DiskPosition[i].x() > 0 - diskWidth[i] / 2)
            {
                DiskPosition[i].setX(DiskPosition[i].x() - 5);
            }
            else
            {
                PositionX[i] = false;
                PositionY[i] = true;
            }
        }
        // Down
        if (PositionY[i])
        {
            if (DiskPosition[i].y() < lastEmptyPositionB)
            {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else
            {
                lastEmptyPositionB -= 20;
                PositionY[i] = false;
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