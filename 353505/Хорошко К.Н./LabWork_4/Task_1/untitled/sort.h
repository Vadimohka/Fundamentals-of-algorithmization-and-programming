#ifndef SORT_H
#define SORT_H
#include "rectangle.h"
#include "mainwindow.h"


class Rectangle;
class MainWindow;

class sort
{
public:
    sort();
    static void quick_sort(int* a, int left, int right, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int n);
    static void heapify(int* arr, int n, int i, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int num);
    static void heapSort(int* arr, int n, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int num);
    static void merge(int* array, int const left, int const mid, int const right, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int num);
    static void mergeSort(int* array, int const begin, int const end, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int num);
    static int binsearch(int* arr, int l, int r, int digit);
};

#endif // SORT_H
