#pragma once

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QGraphicsObject>

class HanoiTowers : public QGraphicsObject {
public:
    QRectF boundingRect() const;
    HanoiTowers();
    ~HanoiTowers();
    void animateDisk(int number, char out, char to);
    bool finished;
    int minA = 230, minB = 230, minC = 230;
    int N = 1;
        void setN(int arg1);
    bool party = false;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private:
    bool firstfirst = true;
    bool first[10]{true, true, true, true, true, true, true, true, true, true};
    bool move[10]{};
    bool down[10]{};
    QTimer *timer;
    int posX[10]{};
    int posY[10]{};
    int towerPos[3] = {-300, 0, 300}; // X positions of the towers
    int diskWidth[10] = {240, 220, 200, 180, 160, 140, 120, 100, 80, 60}; // Width of disks

    int diskHeight = 20; // Height of disks

public:
    bool isChanging = true;
    int posN[10] = {180, 160, 140, 120, 100, 80, 60, 40, 20, 0};
    int posMinN[10] = {-180, -160, -140, -120, -100, -80, -60, -40, -20, 0};

};
