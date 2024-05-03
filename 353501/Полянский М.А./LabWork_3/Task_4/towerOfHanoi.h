#ifndef TOWERS_H
#define TOWERS_H

#include <QGraphicsItem>
#include <QPainter>

class towers : public QGraphicsItem
{
public:
    towers();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    void changeNumberOfRings(int arg);
    void getn(int num);
    void animate(int num, int from, int to);
    bool finished = false;
    int lastEmptyPositionA = 230;   
    int lastEmptyPositionB = 230;   
    int lastEmptyPositionC = 230;   
    bool isChanging = true;  
    int MinpositionN[10] = {-180, -160, -140, -120, -100, -80, -60, -40, -20, 0};          
    
    int getN() const;
    int n = 3;
    int posN[10] = {180, 160, 140, 120, 100, 80, 60, 40, 20, 0};  
protected:
    
    QPointF DiskPosition[10];  
    bool PositionY[10]{};
    bool PositionX[10]{};
    
    bool diskUnused[10] = {true,true,true,true,true,true,true,true,true,true};  
    int diskWidth[10] = {240, 220, 200, 180, 160, 140, 120, 100, 80, 60}; 
    int diskHeight = 20;           
    int TowerX[3] = {-300, 0, 300};                               
    void update();

};

#endif // TOWERS_H
