#ifndef PICTUREDARRAY_H
#define PICTUREDARRAY_H

#include "indexofarray.h"

#include <QVector>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPointer>
#include <QEventLoop>
#include <QTimer>

class PicturedArray : public QGraphicsItem
{
public:
    PicturedArray();

    void push_back(int num, QColor color);
    void updateArray();
    void setScene(QGraphicsScene* scene);
    int size();
    void swap(int first, int second);
    void swapCopy(int first, int second);
    void clear();
    void resetColors();

    QVector<std::pair<double, QColor>> &getArray();
    QVector<std::pair<double, QColor>> &getAux();

    void lookingForMedians();

    // void Merge(int low, int mid, int high);
    // void mergesort(int low, int high);
    void QuickSort(int left, int right);
    // void heapify(int n, int i);
    // void heapSort(int n);

    // int BinSearch(int digit);

    // void mergeSortForTime(int low, int high);
    // void mergeForTime(int low, int mid, int high);
    // long long timeMergeSort();

    // void quickSortForTime(int left, int right);
    // long long timeQuickSort();

    // void heapSortForTime(int n);
    // void heapifyForTime(int n, int i);
    // long long timeHeapSort();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;


private:

    QVector <std::pair<double, QColor>> array, aux, copyOfArray, copyOfAux;
    QVector <IndexOfArray*> indexesOfArray;

    QGraphicsScene* graphicsScene;
    QGraphicsView* graphicsView;
};

#endif // PICTUREDARRAY_H
