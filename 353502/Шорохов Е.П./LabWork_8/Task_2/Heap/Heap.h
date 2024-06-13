//
// Created by shosh on 5/30/24.
//

#ifndef LABWORK_8_HEAP_H
#define LABWORK_8_HEAP_H


#include <memory>

class Heap {
    std::unique_ptr<int[]> array;
    int size = 0;
    int capacity = 1;
    void siftUp(int index);
    void siftDown(int index);
    void buildHeap();
};


#endif //LABWORK_8_HEAP_H
