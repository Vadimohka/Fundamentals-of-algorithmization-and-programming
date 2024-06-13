#ifndef SORT_H
#define SORT_H

#include <QCoreApplication>
#include <QDebug>
#include <QGraphicsScene>
#include <QPainter>
#include <QThread>
#include <QTime>
#include <algorithm>

const int SCENEWIDTH = 930;
const int SCENEHEIGHT = 510;
const int SLEEP_TIME = 10;
const int THOUSAND = 1000;

class Sort : public QGraphicsScene
{
public:
    Sort();
    void setArr(QVector<int>);
    QString heapSort();
    QString quickSort();
    QString mergeSort();
    QString interpolationSort();
    int binSearch(int);
    int binPow(int, int, int);
    QVector<int> getArr();

private:

    QVector<int> arr;
    QString time;
    int millis;
    int maxNum;
    void drawArr(int, int);
    void ending();
    void setMaxNum();

    void heapify(int, int);

    void quickSort(int, int);
    int partition(int, int);

    void mergeSort(int, int);
    void merge(int, int, int);

    void interpolationSort(int, int, int, int);
};

#endif // SORT_H
