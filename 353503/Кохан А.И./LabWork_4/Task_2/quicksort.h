#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QApplication>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QThread>
#include <QVector>

class QuickSort
{
public:
    void static quickSort(QVector<int> &arr,
                          QVector<QGraphicsRectItem *> &rects,
                          QVector<QGraphicsTextItem *> &textNumbers,
                          int sceneHeight,
                          int maxNumber,
                          int sceneWidth,
                          int msleepTime,
                          QGraphicsScene *scene,
                          int low,
                          int high);

private:
    int static partition(QVector<int> &arr,
                         QVector<QGraphicsRectItem *> &rects,
                         QVector<QGraphicsTextItem *> &textNumbers,
                         int sceneHeight,
                         int maxNumber,
                         int sceneWidth,
                         int msleepTime,
                         QGraphicsScene *scene,
                         int low,
                         int high);
    void static updateRectsAndText(QVector<int> &arr,
                                   QVector<QGraphicsRectItem *> &rects,
                                   QVector<QGraphicsTextItem *> &textNumbers,
                                   int sceneHeight,
                                   int maxNumber,
                                   int sceneWidth,
                                   int i,
                                   int j);
};

#endif // QUICKSORT_H
