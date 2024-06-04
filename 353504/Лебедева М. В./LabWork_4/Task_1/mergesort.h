#ifndef MERGESORT_H
#define MERGESORT_H

#include <QApplication>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QThread>
#include <QVector>

class MergeSort
{
public:
    void static mergeSort(QVector<int> &arr,
                          QVector<QGraphicsRectItem *> &rects,
                          int sceneHeight,
                          int maxNumber,
                          int sceneWidth,
                          int msleepTime,
                          QGraphicsScene *scene,
                          int l,
                          int r);

private:
    void static merge(QVector<int> &arr,
                      QVector<QGraphicsRectItem *> &rects,
                      int sceneHeight,
                      int maxNumber,
                      int sceneWidth,
                      int msleepTime,
                      QGraphicsScene *scene,
                      int l,
                      int m,
                      int r);

    void static updateRectsAndText(QVector<int> &arr,
                                   QVector<QGraphicsRectItem *> &rects,
                                   int sceneHeight,
                                   int maxNumber,
                                   int sceneWidth,
                                   int i,
                                   int j);
};

#endif // MERGESORT_H
