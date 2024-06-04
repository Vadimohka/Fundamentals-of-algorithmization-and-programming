//
// Created by u on 09.05.24.
//

#ifndef TASK1_MAIN_WINDOW_H
#define TASK1_MAIN_WINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsObject>
#include <QCoreApplication>
#include <QPainter>
#include <QGraphicsView>
#include "../src/moving_rect.h"
#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <random>


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget
{
Q_OBJECT

private slots:
    void qs();
    void hs();
    void ms();
    void is();
    void restart();
    void updateWindow();

private:
    std::mt19937_64 rnd;
    std::vector<moving_rect> columns;
    bool solving = false;
    int time;

    void shuffle(std::vector<moving_rect> &v);

    void quicksort(int L, int R);
    void heapify(int n, int i);
    void heapSort(int n);
    void mergeSort(int left, int right);
    void interpolationSort();
    void merge(int left, int mid, int right);

public:
    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

private:
    Ui::main_window *ui;
    QGraphicsScene *scene;
};


#endif //TASK1_MAIN_WINDOW_H
