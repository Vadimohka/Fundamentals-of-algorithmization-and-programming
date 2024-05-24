#ifndef SORTVIEW_H
#define SORTVIEW_H

#include <QVector>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QDebug>
#include <vector>
#include <QThread>
#include <QTime>
#include <QEventLoop>
#include <QTimer>
#include <QElapsedTimer>
#include <QApplication>

class SortView : public QObject
{
   Q_OBJECT
public:
    SortView(QGraphicsScene* scene);
    void setArrSize(const long long n);
    void randArr();
    void showArr();
    void doQSort(const long long left, const long long right);
    void doMergeSort(const long long left, const long long right);
    void doHeapSort();
    long long doBinSearch(long long n);
    static long long op;
    void setDelay(int n);
    const QVector<long long>& getArray();
    void  doInterpolationSort();
    void  interpolationSort(QVector<long long> &arr, long long low, long long high);
    long long binpow(long long a, long long n, long long q);
    long long getArrSize();
private:

    void setRect(long long h, long long pos);
    void hilight(long long index);
   // void merge(const long long left, const long long mid, const long long right);
    void swapRect(long long index1, long long index2);
    void heapify(long long n, long long i);
    double rectWidth;
    QVector<long long> array;
    QVector<QGraphicsRectItem*> visualArray;
    QGraphicsScene* scene;
    int delay = 0;


};

#endif // SORTVIEW_H
