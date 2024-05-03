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

    QVector<std::pair<int, QColor>> &getArray();
    QVector<std::pair<int, QColor>> &getAux();

    void Merge(int low, int mid, int high);
    void mergesort(int low, int high);
    void QuickSort(int left, int right);
    void heapify(int n, int i);
    void heapSort(int n);
    void interpolationSort(QVector<std::pair<int, QColor> > &sequence, int size);

    int BinSearch(int digit);
    long long binpow (int digit, int powder, int mod);

    void mergeSortForTime(int low, int high);
    void mergeForTime(int low, int mid, int high);
    void quickSortForTime(int left, int right);
    void heapSortForTime(int n);
    void heapifyForTime(int n, int i);
    void interpolationSortForTime(QVector<std::pair<int, QColor> > &sequence, int size);

    long long timeMergeSort();
    long long timeQuickSort();
    long long timeHeapSort();
    long long timeInterpolationSort();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;


private:

    QVector <std::pair<int, QColor>> array, aux, copyOfArray, copyOfAux;
    QVector <IndexOfArray*> indexesOfArray;

    QGraphicsScene* graphicsScene;
    QGraphicsView* graphicsView;
};

#endif // PICTUREDARRAY_H
