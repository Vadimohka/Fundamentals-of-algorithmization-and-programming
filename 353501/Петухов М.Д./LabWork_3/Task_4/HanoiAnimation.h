#pragma once

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QGraphicsObject>


class HanoiTowers : public QGraphicsObject {
private:
    bool wasCalculatedFirstPos[10]{};


    

    QTimer *timer;

    int posY[10]{};    
    const int towerPosXBottom[3] = {-450, -100, 250};
    const int towerYBase = 500;


    const int diskHeight = 20;
    const int towerHeight = 300;

    const int heightestPoint = 100;

    const int minPosEachDisk = {};

    int shiftToBase = 0;
public:
    bool down[10]{};
    bool moveHorizontally[10]{};
    const int towerStickX[3] = {towerPosXBottom[0] + 65, towerPosXBottom[1] + 65, towerPosXBottom[2] + 65};
    const int diskWidth[10] = {140, 130, 120, 110, 100, 90, 80, 70, 60, 50};
    int posX[10]{};
    QRectF boundingRect() const;
    HanoiTowers();
    ~HanoiTowers();

    void setN(int arg1);
    void animate(int number, int start, int end);
    int number = 1;

    bool stop = false;

    int minDiskPosOnStick[3] = {towerYBase - diskHeight, towerYBase - diskHeight, towerYBase - diskHeight};

    int getDiskHeight(){
        return diskHeight;
    }

    bool wasMoved[10]{};
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);



public:
    bool isChanging = true;
};