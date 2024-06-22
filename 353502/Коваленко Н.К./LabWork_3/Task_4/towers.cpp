#include "towers.h"
#include <QRandomGenerator>
#include <QColor>

HanoiTowers::HanoiTowers() : timer(new QTimer(this))
{
}

HanoiTowers::~HanoiTowers()
{
}

QRectF HanoiTowers::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void HanoiTowers::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);

    // Draw the three towers
    painter->setPen(Qt::gray);
    painter->setBrush(Qt::gray);
    painter->drawRect(-305, 30, 10, 250 - 10);
    painter->drawRect(-5, 30, 10, 250 - 10);
    painter->drawRect(295, 30, 10, 250 - 10);

    painter->drawRect(-430, 250, 260, 25);
    painter->drawRect(-130, 250, 260, 25);
    painter->drawRect(+170, 250, 260, 25);

    for (int i = 10 - N; i < 10; i++)
    {
        if (first[i])
        {
            posX[i] = towerPos[0] - diskWidth[i] / 2;
            posY[i] = 250 - (i + 1) * diskHeight;


            first[i] = false;
        }
        if (party) {
            painter->setBrush(QColor(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256)));
            painter->setBrush(QColor(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256)));
        }
        else
        {
            painter->setPen(QColor(100 * cos(2 * M_PI / 10 * (10 - i)) + 100, 100 * cos(2 * M_PI / 10 * (10 - i) + M_PI / 2) + 100, 100 * cos(2 * M_PI / 10 * (10 - i) + M_PI) + 100));
            painter->setBrush(QColor(100 * cos(2 * M_PI / 10 * (10 - i)) + 100, 100 * cos(2 * M_PI / 10 * (10 - i) + M_PI / 2) + 100, 100 * cos(2 * M_PI / 10 * (10 - i) + M_PI) + 100));
        }

        painter->drawRect(posX[i], posY[i] + posN[N - 1], diskWidth[i], diskHeight);

        if (isChanging) {
            minA = 230 - N * diskHeight;
        }
    }
}

void HanoiTowers::setN(int arg1)
{
    N = arg1;
    update();
}

void HanoiTowers::animate(int number, char from, char to)
{
    int i = number;

    // Up
    if (!down[i])
    {
        if (posY[i] > posMinN[N - 1])
        {
            posY[i] -= 5;
        }
        else
        {
            move[i] = true;
        }
    }
    ///////////////////////////////// A -> B
    if (from == 'A' && to == 'B')
    {
        if (move[i])
        {
            if (posX[i] < 0 - diskWidth[i] / 2)
            {
                posX[i] += 5;
            }
            else
            {
                move[i] = false;
                down[i] = true;
            }
        }
        // Down
        if (down[i])
        {
            if (posY[i] < minB)
            {
                posY[i] += 5;
            }
            else
            {
                minB -= 20;
                finished = true;
                down[i] = false;
            }
        }
    }
    ///////////////////////////////// A -> C
    if (from == 'A' && to == 'C')
    {
        if (move[i])
        {
            if (posX[i] < 300 - diskWidth[i] / 2)
            {
                posX[i] += 5;
            }
            else
            {
                move[i] = false;
                down[i] = true;
            }
        }
        // Down
        if (down[i])
        {
            if (posY[i] < minC)
            {
                posY[i] += 5;
            }
            else
            {
                minC -= 20;
                finished = true;
                down[i] = false;
            }
        }
    }
    ///////////////////////////////// B -> A
    if (from == 'B' && to == 'A')
    {
        if (move[i])
        {
            if (posX[i] > -300 - diskWidth[i] / 2)
            {
                posX[i] -= 5;
            }
            else
            {
                move[i] = false;
                down[i] = true;
            }
        }
        // Down
        if (down[i])
        {
            if (posY[i] < minA)
            {
                posY[i] += 5;
            }
            else
            {
                minA -= 20;
                finished = true;
                down[i] = false;
            }
        }
    }
    ///////////////////////////////// B -> C
    if (from == 'B' && to == 'C')
    {
        if (move[i])
        {
            if (posX[i] < 300 - diskWidth[i] / 2)
            {
                posX[i] += 5;
            }
            else
            {
                move[i] = false;
                down[i] = true;
            }
        }
        // Down
        if (down[i])
        {
            if (posY[i] < minC)
            {
                posY[i] += 5;
            }
            else
            {
                minC -= 20;
                finished = true;
                down[i] = false;
            }
        }
    }
    ///////////////////////////////// C -> A
    if (from == 'C' && to == 'A')
    {
        if (move[i])
        {
            if (posX[i] > -300 - diskWidth[i] / 2)
            {
                posX[i] -= 5;
            }
            else
            {
                move[i] = false;
                down[i] = true;
            }
        }
        // Down
        if (down[i])
        {
            if (posY[i] < minA)
            {
                posY[i] += 5;
            }
            else
            {
                minA -= 20;
                finished = true;
                down[i] = false;
            }
        }
    }
    ///////////////////////////////// C -> B
    if (from == 'C' && to == 'B')
    {
        if (move[i])
        {
            if (posX[i] > 0 - diskWidth[i] / 2)
            {
                posX[i] -= 5;
            }
            else
            {
                move[i] = false;
                down[i] = true;
            }
        }
        // Down
        if (down[i])
        {
            if (posY[i] < minB)
            {
                posY[i] += 5;
            }
            else
            {
                minB -= 20;
                finished = true;
                down[i] = false;
            }
        }
    }


    update();
}
