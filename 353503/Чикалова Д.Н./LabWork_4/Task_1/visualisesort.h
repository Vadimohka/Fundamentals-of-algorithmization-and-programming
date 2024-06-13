#ifndef VISUALISESORT_H
#define VISUALISESORT_H

#include <QApplication>
#include <QEventLoop>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QObject>
#include <QPropertyAnimation>
#include <QThread>
#include <QTime>
#include <QTimer>
#include <QDebug>

class VisualiseSort : public QObject
{
    Q_OBJECT
public:

    VisualiseSort(int* arr, int size, char flag, QGraphicsScene& scene)
        :_scene(&scene),_size(size), _flag(flag),_delay(0), _arr(new int[size])
    {
        _arr = arr;
        _items.clear();
        outputArray();
        timer = new QElapsedTimer();
    }
    void outputArray();
    void startVisualisation();
    void skip(int ms);
    void SuccessSorting();
    void changeHeight(QGraphicsRectItem &item_1, QGraphicsRectItem &item_2);
    void changeHeight(QGraphicsRectItem &item_1, qreal height);
    qreal getTime();
    void QuickSort(int* arr, int start, int end);
    void HeapSort(int* arr, int size);
    void heapify(int* arr, int size, int i);
    void MergeSort(int* arr, int size);
    void Merge(int* target, int size_target, int* arr_1 , int size_1 , int* arr_2 , int size_2);
    int BinarySearch(int* arr,int left,int right, int target);

private:
    QGraphicsScene* _scene;
    QList<QGraphicsRectItem*> _items;
    QTimer* _timer{};
    QGraphicsRectItem* _item_1{};
    QGraphicsRectItem* _item_2{};
    QElapsedTimer* timer;
    long long _delay = 0;
    int* _arr;
    int _size;
    char _flag;
};

#endif // VISUALISESORT_H
