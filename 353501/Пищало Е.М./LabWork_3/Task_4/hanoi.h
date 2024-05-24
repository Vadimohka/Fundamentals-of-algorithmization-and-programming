#ifndef HANOI_H
#define HANOI_H


#include<QPainter>
#include<QGraphicsObject>

class hanoi : public QGraphicsObject
{
public:
    bool isChanging = true;
    int n = 1;
    void getn(int num);
    hanoi();
    void changeNumberOfRings(int arg);
    void animate(int num,char from,char to);
    bool finished = false;
    int lastEmptyPositionA = 230;
    int lastEmptyPositionB = 230;
    int lastEmptyPositionC = 230;
    int posN[10] = {180, 160, 140, 120, 100, 80, 60, 40, 20, 0};
protected:
    bool on_positionY[10]{};
    bool on_PositionX[10]{};
    int posMinN[10] = {-180, -160, -140, -120, -100, -80, -60, -40, -20, 0};
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;
    int diskWidth[10] = {240, 220, 200, 180, 160, 140, 120, 100, 80, 60}; // Width of disks
    int diskHeight = 20; // Height of disks
    QPointF disk_pos[10];
    int TowerX[3] = {-300, 0, 300};
    bool disk_unused[10] = {true,true,true,true,true,true,true,true,true,true};

};

#endif // HANOI_H
