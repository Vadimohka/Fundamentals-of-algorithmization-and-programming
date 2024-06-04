#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QApplication>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QThread>
#include <QVector>

class BubbleSort
{
public:
    void static bubbleSort(QVector<int> &arr,
                           QVector<QGraphicsRectItem *> &rects,
                           QVector<QGraphicsTextItem *> &textNumbers,
                           int sceneHeight,
                           int maxNumber,
                           int sceneWidth,
                           int msleepTime,
                           QGraphicsScene *scene);

private:
    void static updateRectsAndText(QVector<int> &arr,
                                   QVector<QGraphicsRectItem *> &rects,
                                   QVector<QGraphicsTextItem *> &textNumbers,
                                   int sceneHeight,
                                   int maxNumber,
                                   int sceneWidth,
                                   int i,
                                   int j);
};

#endif // BUBBLESORT_H
