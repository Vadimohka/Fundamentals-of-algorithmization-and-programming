#ifndef SORTER_H
#define SORTER_H
#include <QGraphicsRectItem>
class Sorter : public QObject
{
    Q_OBJECT
public:
    Sorter();
    void mergeSort(QVector<float>& palki,int low,int high);
    void quickSort(QVector<float>& palki, int low, int high);
    void heapSort(QVector<float>& palki);
    void bubbleSort(QVector<float>& palki);
    int BinarySearch(QVector<float>& palki,int l,int r,int x);
    void interpolationSort(QVector<float>& palki,int l,int h);
    int BinPow(int digit, int power, int mod);
signals:
    void updatesignal();
private:
    int partition(QVector<float>& palki, int low, int high);
    void heapify(QVector<float>& palki, int size, int root);
};
#endif // SORTER_H
