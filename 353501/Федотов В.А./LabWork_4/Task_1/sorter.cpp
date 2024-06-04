#include "sorter.h"
#include <qapplication.h>
#include <qbrush.h>
#include <qcontainerfwd.h>
#include <qcoreapplication.h>
#include <qgraphicsscene.h>
#include <qnamespace.h>
#include <qpalette.h>
#include <qpen.h>
#include <qpoint.h>
#include <qthread.h>
#include <algorithm>

Sorter::Sorter(QVector<int> *array, QGraphicsScene *scene){
    this->array = array;
    this->scene = scene;

    scene_W = 914;
    scene_H = 412;

    speed = 0;
}

void Sorter::setSpeed(int speed) { this->speed = 100 - speed * 10; }

double Sorter::getTime(int sortIndex) {
    switch (sortIndex) {
        case 0:
            return heapSortTime;
        case 1:
            return quickSortTime;
        case 2:
            return mergeSortTime;
        default:
            return -1;
    }

}

// int Sorter::partition(int start, int end){
// 	int pivot = array->at(end);
 
//     int i = start - 1;
//     for (int j = start; j <= end - 1; j++) {
//         if (array->at(j) <= pivot){
//             i++;
//             array->swapItemsAt(i, j);
//             visualize(i, j);
//         }
//     }

//     array->swapItemsAt(i+1, end);
//     visualize(i+1, end);
//     return (i+1);
// }

int Sorter::partition(int start, int end){
	int pivot = array->at(start);
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (array->at(i) <= pivot)
            count++;
    }
 
    int pivotIndex = start + count;
    array->swapItemsAt(pivotIndex, start);
    visualize(pivotIndex, start);
    
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (array->at(i) <= pivot) {
            i++;
        }
 
        while (array->at(j) > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            array->swapItemsAt(i, j);
            visualize(i, j);
            j--;
            i++;
        }
    }
 
    return pivotIndex;
}

void Sorter::quickSort(int start, int end){
    if (start >= end)
	    return;

    auto startTime = std::chrono::high_resolution_clock::now();

	int p = partition(start, end);
	quickSort(start, p - 1);  //l
	quickSort(p + 1, end);  //r

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    quickSortTime = duration.count();    

    visualize();
}

void Sorter::heapify(int N, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && array->at(l) > array->at(largest))
        largest = l;

    if (r < N && array->at(r) > array->at(largest))
        largest = r;

    if (largest != i) {
        array->swapItemsAt(i, largest);
        visualize(i, largest);

        heapify(N, largest);
    }
}

void Sorter::heapSort(int N){
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(N, i);

    for (int i = N - 1; i > 0; i--) {
        array->swapItemsAt(0, i);
        visualize(0, i);
        QThread::msleep(speed);
        QCoreApplication::processEvents();
        heapify(i, 0);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    heapSortTime = duration.count();    

    visualize();
}

void Sorter::merge(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    QVector<int> leftArr(n1);
    QVector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = array->at(left + i);
    for (int j = 0; j < n2; ++j)
        rightArr[j] = array->at(mid + 1 + j);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            array->replace(k, leftArr[i]);
            visualize(k);
            ++i;
        } else {
            array->replace(k, rightArr[j]);
            visualize(k);
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array->replace(k, leftArr[i]);
        visualize(k);

        ++i;
        ++k;
    }

    while (j < n2) {
        array->replace(k, rightArr[j]);
        visualize(k);
        ++j;
        ++k;
    }
}

void Sorter::mergeSort(int left, int right) {
    auto startTime = std::chrono::high_resolution_clock::now();

    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    mergeSortTime = duration.count();  

    visualize();
}

int Sorter::binarySearch(int target) {
    int left = 0;
    int right = array->size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        visualize(-1, -1, mid);

        if (array->at(mid) == target) {
            return mid;
        } else if (array->at(mid) < target) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return -1;
}

void Sorter::visualize(int swap_i, int swap_j, int mid){
    double column_W = scene_W / array->size();
    int max = *std::max_element(array->begin(), array->end());
    double k = (double)scene_H / (double)max;

    scene->clear();
    for (int i = 0; i < array->size(); i++) {
        double column_H = array->at(i) * k;
        double x = -(scene_W / 2) + (i * column_W);
        double y = -(scene_H / 2) + (scene_H - column_H);

        QGraphicsRectItem *columnItem = new QGraphicsRectItem;

        columnItem->setRect(QRectF(0, 0, column_W, column_H ));
        columnItem->setPos(x, y);
        columnItem->setPen(QPen(Qt::black, 1));
        
        if (i == swap_i || i == swap_j) {
            columnItem->setBrush(Qt::red);
        } else if (i == mid) {
            columnItem->setBrush(Qt::blue);
        } else {
            columnItem->setBrush(Qt::white);
        }

        scene->addItem(columnItem);
    }

    QThread::msleep(speed);
    QCoreApplication::processEvents();
}

