#ifndef BINSEARCH_H
#define BINSEARCH_H

#include <QApplication>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QThread>
#include <QVector>

class BinSearch
{
public:
    void static binsearch(QVector<int> &arr,
                          int digit,
                          QVector<QGraphicsRectItem *> &rects,
                          QGraphicsScene *scene,
                          int msleepTime);
};

#endif // BINSEARCH_H
