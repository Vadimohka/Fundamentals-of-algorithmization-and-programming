#pragma once

#include <QGraphicsObject>
#include <QVector>

class RectArray : public QGraphicsObject
{

public:
    RectArray();
    ~RectArray();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int number = 1;
    QVector<int> generateRandomArray(int n);
    QVector<int> getColor(int n);
    void updateNumber();

    int width = 900, height = 500;
    bool allowSort = true;
    bool allowUpdateNumber = true;

    bool isSorted();
    template <typename T>
    void swap(T& a, T& b, int one, int two);

    void heapSorting();
    template <typename T>
    void heapify(QVector<T>& arr, int n, int i);
    template <typename T>
    void heapSort(QVector<T>& arr);


    void quickSorting();
    template <typename T>
    int partition(QVector<T>& arr, int low, int high);
    template <typename T>
    void quickSort(QVector<T>& arr, int low, int high);

    void mergeSorting();
    template <typename T>
    void merge(QVector<T>& arr, int left, int mid, int right);
    template <typename T>
    void mergeSort(QVector<T>& arr, int left, int right);

    int binarySearch(int target);


private:
    QVector<int> toSort;
    QVector<int> color;

};
