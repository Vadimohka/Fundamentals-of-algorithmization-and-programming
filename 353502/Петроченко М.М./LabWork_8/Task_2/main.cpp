//
// Created by acryoz on 30.05.24.
//
#include "bin_heap_vec.h"

int main() {
    VecBinHeap<int> heap;
    heap.insert(1);
    heap.print();
    heap.insert(2);
    heap.print();
    heap.insert(0);
    heap.print();
    heap.insert(-1);
    heap.print();
    heap.insert(8);
    heap.print();
    heap.insert(1);
    heap.print();
}