#include "towers.h"

Towers::Towers() {}


void Towers::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);

    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);

    painter->drawRect(-305, 30, 10, 250 - 10);
    painter->drawRect(-5, 30, 10, 250 - 10);
    painter->drawRect(295, 30, 10, 250 - 10);

    painter->drawRect(-430, 250, 260, 25);
    painter->drawRect(-130, 250, 260, 25);
    painter->drawRect(+170, 250, 260, 25);

    for(int i = 10 - n;i < 10;++i){
        if(DiskUnused[i]){
            DiskPosition[i].setX(TowerX[0] - DiskWidth[i] / 2);
            DiskPosition[i].setY(250 - (i + 1) * DiskHeight);
            DiskUnused[i] = false;
        }
        if(i % 2 == 0){
            painter->setBrush(Qt::green);
            painter->setPen(Qt::black);
            painter->drawRect(DiskPosition[i].x(), DiskPosition[i].y() + posN[n - 1], DiskWidth[i], DiskHeight);
            continue;
        }
        painter->setBrush(Qt::green);
        painter->setPen(Qt::black);
        painter->drawRect(DiskPosition[i].x(), DiskPosition[i].y() + posN[n - 1], DiskWidth[i], DiskHeight);
    }

    if (isChanging) {
        lastEmptyPositionA = 230 - n * DiskHeight;
    }
}


QRectF Towers::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void Towers::changeNumberOfRings(int arg)
{
    n = arg;
    update();
}

void Towers::SetN(int num)
{
    n = num;
    update();
}
void Towers::animate(int num, char from, char to)
{
    int i = num;
    if (!onPositionY[i]) {
        if (DiskPosition[i].y() > posMinN[n - 1]) {
            DiskPosition[i].setY(DiskPosition[i].y() - 5);
        }
        else {
            onPositionX[i] = true;
        }
    }

    if (from == 'A' && to == 'B') {
        if (onPositionX[i]) {
            if (DiskPosition[i].x() < 0 - DiskWidth[i] / 2) {
                DiskPosition[i].setX(DiskPosition[i].x() + 5);
            }
            else {
                onPositionX[i] = false;
                onPositionY[i] = true;
            }
        }

        if (onPositionY[i]) {
            if (DiskPosition[i].y() < lastEmptyPositionB){
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else {
                lastEmptyPositionB -= 20;
                onPositionY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 'A' && to == 'C') {
        if (onPositionX[i]) {
            if (DiskPosition[i].x() < 300 - DiskWidth[i] / 2) {
                DiskPosition[i].setX(DiskPosition[i].x() + 5);
            }
            else {
                onPositionX[i] = false;
                onPositionY[i] = true;
            }
        }

        if (onPositionY[i]) {
            if (DiskPosition[i].y() < lastEmptyPositionC) {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else {
                lastEmptyPositionC -= 20;
                onPositionY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 'B' && to == 'A') {
        if (onPositionX[i]) {
            if (DiskPosition[i].x() > -300 - DiskWidth[i] / 2){
                DiskPosition[i].setX(DiskPosition[i].x() - 5);
            }
            else {
                onPositionX[i] = false;
                onPositionY[i] = true;
            }
        }

        if (onPositionY[i]) {
            if (DiskPosition[i].y() < lastEmptyPositionA) {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else {
                lastEmptyPositionA -= 20;
                onPositionY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 'B' && to == 'C')  {
        if (onPositionX[i]) {
            if (DiskPosition[i].x() < 300 - DiskWidth[i] / 2) {
                DiskPosition[i].setX(DiskPosition[i].x() + 5);
            }
            else {
                onPositionX[i] = false;
                onPositionY[i] = true;
            }
        }

        if (onPositionY[i]) {
            if (DiskPosition[i].y() < lastEmptyPositionC) {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else {
                lastEmptyPositionC -= 20;
                onPositionY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 'C' && to == 'A') {
        if (onPositionX[i]) {
            if (DiskPosition[i].x() > -300 - DiskWidth[i] / 2) {
                DiskPosition[i].setX(DiskPosition[i].x() - 5);
            }
            else {
                onPositionX[i] = false;
                onPositionY[i] = true;
            }
        }

        if (onPositionY[i]) {
            if (DiskPosition[i].y() < lastEmptyPositionA) {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else {
                lastEmptyPositionA -= 20;
                onPositionY[i] = false;
                finished = true;
            }
        }
    }

    if (from == 'C' && to == 'B') {
        if (onPositionX[i]) {
            if (DiskPosition[i].x() > 0 - DiskWidth[i] / 2) {
                DiskPosition[i].setX(DiskPosition[i].x() - 5);
            }
            else {
                onPositionX[i] = false;
                onPositionY[i] = true;
            }
        }

        if (onPositionY[i]) {
            if (DiskPosition[i].y() < lastEmptyPositionB) {
                DiskPosition[i].setY(DiskPosition[i].y() + 5);
            }
            else  {
                lastEmptyPositionB -= 20;
                onPositionY[i] = false;
                finished = true;
            }
        }
    }
    update();
}
