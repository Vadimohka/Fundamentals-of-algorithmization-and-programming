#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <QApplication>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QThread>
#include <QVector>

class HeapSort
{
public:
    void static heapSort(QVector<int> &arr,
                         QVector<QGraphicsRectItem *> &rects,
                         QVector<QGraphicsTextItem *> &textNumbers,
                         int sceneHeight,
                         int maxNumber,
                         int sceneWidth,
                         int msleepTime,
                         QGraphicsScene *scene);

private:
    void static heapify(QVector<int> &arr,
                        QVector<QGraphicsRectItem *> &rects,
                        QVector<QGraphicsTextItem *> &textNumbers,
                        int sceneHeight,
                        int maxNumber,
                        int sceneWidth,
                        int msleepTime,
                        QGraphicsScene *scene,
                        int n,
                        int i);

    void static updateRectsAndText(QVector<int> &arr,
                                   QVector<QGraphicsRectItem *> &rects,
                                   QVector<QGraphicsTextItem *> &textNumbers,
                                   int sceneHeight,
                                   int maxNumber,
                                   int sceneWidth,
                                   int i,
                                   int j);
};

#endif // HEAPSORT_H
