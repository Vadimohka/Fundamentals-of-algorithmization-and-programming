#ifndef INTERPOLATIONSORT_H
#define INTERPOLATIONSORT_H

#include <QApplication>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QThread>
#include <QVector>

class InterpolationSort
{
public:
    void static interpolationSort(QVector<int> &arr,
                                  QVector<QGraphicsRectItem *> &rects,
                                  int sceneHeight,
                                  int maxNumber,
                                  int sceneWidth,
                                  int msleepTime,
                                  QGraphicsScene *scene);

private:
    void static updateRectsAndText(QVector<int> &arr,
                                   QVector<QGraphicsRectItem *> &rects,
                                   int sceneHeight,
                                   int maxNumber,
                                   int sceneWidth,
                                   int i,
                                   int j);
};

#endif // INTERPOLATIONSORT_H
