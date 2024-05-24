//
// Created by darina on 4/10/24.
//

#ifndef TASK4_MAINWINDOW_H
#define TASK4_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <qgraphicsscene.h>
#include "../hanoi/Hanoi.h"
#include "../animation/MovingRectangle.h"
#include "../animation/TowersBase.h"

#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
    class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QMainWindow {
Q_OBJECT

public:
    mainwindow();

protected:
    Ui::mainwindow *ui;
    QGraphicsScene *scene;
    TowersBase *towersbase = new TowersBase();

private:
    QVector<MovingRectangle*> tower[4];
    int centre[4] = {0, -190, 10, 210};
    bool on_scene = 0;
    const int h = 5;
    MovingRectangle *currentrectangle;

    QTimer *left_tick;
    QTimer *right_tick;
    QTimer *up_tick;
    QTimer *down_tick;
    QString answer;

    int up_mx = -220, down_mx, stop_pos;
    bool is_animated = 0;
    int cur = 0;
    bool reach_1 = 0, reach_2 = 0, reach_3 = 1;

    void func(int st, int fin);

private slots:
    void perform_task(int n);
    void on_downmove();
    void on_leftmove();
    void on_rightmove();
    void on_upmove();
    void animate();
};


#endif //TASK4_MAINWINDOW_H
