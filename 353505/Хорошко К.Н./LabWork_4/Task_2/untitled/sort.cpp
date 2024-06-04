#include "sort.h"
#include "QTimer"
#include "QEventLoop"
#include <QCoreApplication>

sort::sort()
{

}


void sort::quick_sort(int* a, int left, int right, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int n){
    Rectangle::foo(a,n,max,rect, w0, h0, mainWindowPtr);
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
            Rectangle::foo(a,n,max,rect, w0, h0, mainWindowPtr);
            QEventLoop loop;
            QTimer::singleShot(100, &loop, &QEventLoop::quit); // Ожидание 0.5 секунды
            loop.exec();
        }
    }

    if (r > left) {

        quick_sort(a, left, r, max, rect, w0, h0, mainWindowPtr, n);

    }
    if (l < right){

        quick_sort(a, l, right, max, rect, w0, h0, mainWindowPtr, n);

    }
}

int sort::binsearch(int* arr, int l, int r, int digit){

    if (r-l == 0){
        if (arr[l] == digit){
            return l;
        }
        else {
            return -1;
        }
    }

    int mid = arr[(r + l)/2];

    if (mid == digit) {
        return (r+l)/2;
    }

    if (mid > digit){
        return binsearch(arr, l, (r+l)/2, digit);
    }

    if (mid < digit){
        return binsearch(arr,(r+l)/2+1, r, digit);
    }

}

int sort::binpow(int digit, int powder, int mod)
{
    int ans = 1;
    digit %= mod;
    while (powder > 1){
        if(powder % 2 == 1) {
            ans *= digit;
            ans %= mod;
            digit *= digit;
            digit %= mod;
            powder /= 2;
        }
        else{
            digit *= digit;
            digit %= mod;
            powder /= 2;
        }
    }
    ans *= digit;
    ans %= mod;
    return ans;
}
