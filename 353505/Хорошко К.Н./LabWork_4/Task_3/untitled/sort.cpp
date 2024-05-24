#include "sort.h"

sort::sort()
{

}

void sort::quick_sort(int* a, int left, int right){
    int l = left;
    int r = right;
    int pos = a[left + ((a[left] - a[right]) / (a[left] - a[right])) * (right - left)];
    while (l < r){
        while (a[l] < pos){
            l++;
        }
        while (a[r] > pos){
            r--;
        }
        if (l <= r){
            if (l != r){
                int buf = a[l];
                a[l] = a[r];
                a[r] = buf;
            }
            r--;
            l++;
        }
    }

    if (r > left) {

        quick_sort(a, left, r);

    }
    if (l < right){

        quick_sort(a, l, right);

    }
}
