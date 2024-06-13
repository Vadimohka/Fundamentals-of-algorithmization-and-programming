//
// Created by shosh on 5/30/24.
//

#include "Heap.h"

void Heap::siftUp(int index) {
 while (index > 1 && array[index] < array[index / 2]) {
    std::swap(array[index], array[index / 2]);
    index /= 2;
 }
}

void Heap::siftDown(int index) {
 while (2 * index + 1 < size) {
     int left = 2 * index + 1;
     int right = 2 * index + 2;
     int smallest_child_index = left;
     if (right < size && array[left] < array[right]) {
         smallest_child_index = right;
     }
     if (array[index] <= array[smallest_child_index]) {
         break;
     }
     std::swap(array[index], array[smallest_child_index]);
     index = smallest_child_index;
 }
}

void Heap::buildHeap() {
    for (int i = size / 2; i > 0; i--) {
        siftDown(i);
    }
}

