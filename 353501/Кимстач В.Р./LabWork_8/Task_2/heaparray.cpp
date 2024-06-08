#include <iostream>
#include "HeapArray.h"

HeapArray::HeapArray() {
    _capacity = 8;
    _size = 0;
    heap = std::make_unique<int[]> (8);
}

void HeapArray::add(int value) {
    if(_size == _capacity)
        reserve();

    heap[_size] = value;
    _size ++;
    siftUp(_size - 1);
}

int HeapArray::getMax() {
    if(_size == 0)
        throw "out of range";
    return heap[0];
}

void HeapArray::ExtractMax() {
    if(_size == 0)
        return;
    std::swap(heap[0], heap[_size - 1]);
    _size --;
    siftDown(0);
}

void HeapArray::increaseElement(int i, int delta) {
    heap[i] += delta;
    siftUp(i);
}

void HeapArray::decreaseElement(int i, int delta) {
    heap[i] -= delta;
    siftDown(i);
}


void HeapArray::reserve() {
    auto temp = std::make_unique<int[]>(_capacity * 2);
    for(int i = 0; i < _size; i ++)
    {
        temp[i] = std::move(heap[i]);
    }
    _capacity = _capacity * 2;
    std::swap(heap, temp);
}

void HeapArray::siftDown(int i) {
    if(i * 2 + 1 >= _size)
        return;
    if(i * 2 + 2 == _size)
    {
        // one son

        if(heap[i] < heap[i * 2 + 1])
        {
            std::swap(heap[i], heap[i * 2 + 1]);
        }

        return;
    }

    // find max son

    int max_value = heap[i];
    if(heap[i * 2 + 1] > max_value)
        max_value = heap[i * 2 + 1];
    if(heap[i * 2 + 2] > max_value)
        max_value = heap[i * 2 + 2];
    if(heap[i] != max_value)
    {
        if(heap[i * 2 + 1] == max_value)
        {
            std::swap(heap[i * 2 + 1], heap[i]);
            siftDown(i * 2 + 1);
        }
        else
        {
            std::swap(heap[i * 2 + 2], heap[i]);
            siftDown(i * 2 + 1);
        }
    }
}

void HeapArray::siftUp(int i) {
    if(i == 0)
        return;
    /*
     *    0
     * 1    2
     * 3 4 5 6
     */
    int parent = (i + 1) / 2 - 1;
    std::cout << "i " << i << " " << heap[i] << " parent " << parent << " " << heap[parent] << std::endl;
    if(heap[parent] < heap[i])
    {
        std::swap(heap[parent], heap[i]);
        siftUp(parent);
    }
    std::cout << i << " " << parent << " :";
    for(int j = 0; j < _size; j ++)
        std::cout << heap[j] << " ";
    std::cout << '\n';
}

int HeapArray::size() {
    return _size;
}

void HeapArray::clear() {
    while (_size != 0)
        ExtractMax();
}

std::vector<int> HeapArray::GetHeap() {
    std::vector<int> a;
    for(int i = 0; i < _size; i ++)
    {
        a.push_back(heap[i]);
    }
    return a;
}

int HeapArray::findValue(int i, int value) {
    std::cout << i << heap[i] << " value " << value << '\n';
    if(heap[i] == value)
        return i;

    int ret = -1;
    if(i * 2 + 1 < _size && heap[i * 2 + 1] >= value)
        ret = std::max(ret, findValue(i * 2 + 1, value));
    if(i * 2 + 2 < _size && heap[i * 2 + 2] >= value)
        ret = std::max(ret, findValue(i * 2 + 2, value));

    return ret;
}

void HeapArray::increaseValue(int value, int delta) {
    int position = findValue(0, value);
    std::cout << "position " << position << '\n';
    if(position != -1)
    {
        increaseElement(position, delta);
    }
    for(int i = 0; i < _size; i ++)
    {
        std::cout << heap[i] << " ";
    }
    std::cout << '\n';
}

void HeapArray::decreaseValue(int value, int delta) {
    int position = findValue(0, value);
    if(position != -1)
    {
        decreaseElement(position, delta);
    }
}
