#ifndef SORTER_H
#define SORTER_H

#include <QGraphicsRectItem>
#include <QtSwap>
#include <QPainter>
#include <QEventLoop>
#include <QTimer>

class Sorter : public QGraphicsRectItem
{
public:
    Sorter(int *arr, int n);
    void heapSort(int n);
    void quickSort(int first, int last);
    void mergeSort(int first, int last);
    int binSearch(int n, int find);
    int _n;
    int *_arr;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

protected:
    void heapify(int root, int bottom);
    int partition(int start, int end);
    void merge(int left, int mid, int right);

};

#endif // SORTER_H
