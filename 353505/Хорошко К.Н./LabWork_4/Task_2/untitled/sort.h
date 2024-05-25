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
    static int binsearch(int* arr, int l, int r, int digit);
    static int binpow(int digit, int powder, int mod);
};

#endif // SORT_H
