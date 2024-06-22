#include "binsearch.h"

int binSearch(int* arr, int n, int digit)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == digit)
            return mid;
        if (arr[mid] < digit)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
