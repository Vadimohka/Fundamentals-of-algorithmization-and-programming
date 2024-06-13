//
// Created by acryoz on 7.4.24.
//

#include "../headers/binsearch.h"

int binSearch(int* array, int number, int left, int right) {
    int mid = left + (right - left) / 2;
    if (array[mid] == number) {
        return mid;
    } else if (array[mid] != number && left == right) {
        return -1;
    } else if (array[mid] >= number) {
        return binSearch(array, number, left, mid);
    } else {
        return binSearch(array, number, mid + 1, right);
    }
}
