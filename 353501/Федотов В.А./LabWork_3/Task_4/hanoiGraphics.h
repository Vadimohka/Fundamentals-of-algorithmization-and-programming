#pragma once

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QGraphicsObject>
#include <qcontainerfwd.h>
#include <qpoint.h>
#include <qtablewidget.h>
#include <qthread.h>
#include <qcoreevent.h>
#include <qdebug.h>
#include <qtablewidget.h>


class HanoiGraphics : public QGraphicsObject {
    Q_OBJECT
public:
    HanoiGraphics(int num);
    ~HanoiGraphics();

    int getNumDisks();
    int getDiskHeight();
    void solve(int n, int start, int end);
    void setTable (QTableWidget *table);
    void setSpeed(int speed);
    QTableWidget* table;

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void moveDisk(int n, int src, int dst);
    void animate(int n, int src, int dst);

    bool animActive = false;
    bool reachedTop = false;
    bool reachedBottom = false;
    bool reachedDst = false;

    int speed_;

    int tower_H = 250;
    int tower_W = 16;
    int tower_X[3] = {-300 - tower_W/2, -tower_W/2, 300 - tower_W/2};
    int minDisk_H[3] = {250, 250, 250};
    int scene_W = 900;
    
    int disk_H = 20;
    int disk_W[10];
    int pos_X[10];
    int pos_Y[10];
    int numDisks;
    int diskHeightDelta;
    int target_Top = -200;

    int count = 0;

    int anim_src;
    int anim_dst;
    int anim_n;
    
};