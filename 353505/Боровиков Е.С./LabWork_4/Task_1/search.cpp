#include "search.h"

int Search::Binsearch(int *array, int size, int aim) {
    int left = 0, right = size - 1;
    int mid = 0;
    while (right >= left) {
        mid = (right + left) / 2;
        if (array[mid] > aim) { right = mid - 1; }
        else if (array[mid] < aim) { left = mid + 1; }
        else { return mid + 1; }
    }
    return -1;
}
