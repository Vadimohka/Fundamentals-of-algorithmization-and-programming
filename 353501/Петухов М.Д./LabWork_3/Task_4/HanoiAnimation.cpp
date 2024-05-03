#include "HanoiAnimation.h"
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
    painter->setBrush(Qt::white);
    //draw the bottoms of the towers
    painter->drawRect(towerPosXBottom[0], towerYBase, 150, 20);
    painter->drawRect(towerPosXBottom[1], towerYBase, 150, 20);
    painter->drawRect(towerPosXBottom[2], towerYBase, 150, 20);

    //draw towers sticks
    painter->drawRect(towerStickX[0], towerYBase - towerHeight, 20, towerHeight);
    painter->drawRect(towerStickX[1], towerYBase - towerHeight, 20, towerHeight);
    painter->drawRect(towerStickX[2], towerYBase - towerHeight, 20, towerHeight);

    shiftToBase = (10 - number) * diskHeight;

    for(int i = 10 - number; i < 10; i++){
        if(!wasCalculatedFirstPos[i]){
            posX[i] = towerStickX[0] + 10 - diskWidth[i] / 2;
            posY[i] = towerYBase - (10 - number + 1) * diskHeight;

            wasCalculatedFirstPos[i] = true;
        }

        painter->setBrush(Qt::red);

        if(!wasMoved[i]){
            painter->drawRect(posX[i], posY[i] + shiftToBase, diskWidth[i], diskHeight);
        }
        else{
            painter->drawRect(posX[i], posY[i], diskWidth[i], diskHeight);
        }

    }

}

void HanoiTowers::setN(int arg1)
{
    number = arg1;
    update();
}

void HanoiTowers::animate(int number, int start, int end)
{
    int i = number;
    
    if (!down[i]){
        if (posY[i] > heightestPoint){
            wasMoved[i] = true;
            posY[i] -= 5;
        }
        else{
            moveHorizontally[i] = true;
            down[i] = true;
        }
    }
    //horizontally
    if(moveHorizontally[i]){
        if(start == 1 && end == 3 ){
            
            if(posX[i] < towerStickX[2] + 10 - diskWidth[i] / 2){
                wasMoved[i] = true;
                posX[i] += 10;
            }
            else{
                moveHorizontally[i] = false;
            }
            
        }
        else if(start == 1 && end == 2){
            if(posX[i] < towerStickX[1] + 10 - diskWidth[i] / 2){
                wasMoved[i] = true;
                posX[i] += 10;
            }
            else{
                moveHorizontally[i] = false;
            }   
        }
        else if(start == 2 && end == 3){
            if(posX[i] < towerStickX[2] + 10 - diskWidth[i] / 2){
                wasMoved[i] = true;
                posX[i] += 10;
            }
            else{
                moveHorizontally[i] = false;
            }
        }
        else if(start == 2 && end == 1){
            if(posX[i] > towerStickX[0] + 10 - diskWidth[i] / 2){
                wasMoved[i] = true;
                posX[i] -= 10;
            }
            else{
                moveHorizontally[i] = false;
            }
        }
        else if(start == 3 && end == 1){
            if(posX[i] > towerStickX[0] + 10 - diskWidth[i] / 2){
                wasMoved[i] = true;
                posX[i] -= 10;
            }
            else{
                moveHorizontally[i] = false;
            }
        }
        else if(start == 3 && end == 2){
            if(posX[i] > towerStickX[1] + 10 - diskWidth[i] / 2){
                wasMoved[i] = true;
                posX[i] -= 10;
            }
            else{
                moveHorizontally[i] = false;
            }
        }
    }
    //move down
    if(down[i] && !moveHorizontally[i]){
        if(end == 3){
            if(posY[i] < minDiskPosOnStick[2]){
                wasMoved[i] = true;
                posY[i] += 5;
            }
            else{
                down[i] = false;
                stop = true;
            }
        }
        else if(end == 2){
            if(posY[i] < minDiskPosOnStick[1]){
                wasMoved[i] = true;
                posY[i] += 5;
            }
            else{
                down[i] = false;
                stop = true;
            }
        }
        else if(end == 1){
            if(posY[i] < minDiskPosOnStick[0]){
                wasMoved[i] = true;
                posY[i] += 5;
            }
            else{
                down[i] = false;
                stop = true;
            }
        }
    }

    update();
}