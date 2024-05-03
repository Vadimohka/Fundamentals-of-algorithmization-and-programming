#include "quicksort.h"
#include <QDebug>

QuickSort::QuickSort() {}

void QuickSort::qiuckSort(int *arr, int left, int right, QVector <QPair <int, int>>& vec, int &n)
{
    if (left > right) return;
    int p = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < p){

            i++;
            n++;
        }
        while (arr[j] > p) {
            j--;
            n++;
        }

        if (i <= j){
            QuickSort::swap(arr[i], arr[j]);
            n++;
            vec.append(QPair<int, int>(i, j));
            i++;
            j--;
        }
    }
    qiuckSort(arr, left, j, vec, n);
    qiuckSort(arr, i, right, vec, n);

}

void QuickSort::swap(int &i, int &j)
{
    int sw = i;
    i = j;
    j = sw;
}
