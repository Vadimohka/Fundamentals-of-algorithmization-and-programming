//
// Created by u on 09.03.24.
//

#ifndef TASK_MAIN_WINDOW_H
#define TASK_MAIN_WINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsObject>
#include <QCoreApplication>
#include <QPainter>
#include <QGraphicsView>
#include "../src/moving_rect.h"
#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT

private slots:
    void moveRect();
    void restart();
    void solve();
    void updateWindow();

private:
    std::vector<moving_rect> pin[3];
    bool solving = false;
    int pinX[3];
    int cur = -1;
    int curPin;

    void moveP(int fromPin, int toPin);
    void rec(int fromPin, int toPin, int num);

public:
    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

private:
    Ui::main_window *ui;
    QGraphicsScene *scene;
};


#endif //TASK_MAIN_WINDOW_H
