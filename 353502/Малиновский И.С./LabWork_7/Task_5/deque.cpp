#include "deque.h"

template<typename T, size_t K>
Deque<T, K>::Deque() : head(0), tail(0) {
    blocks.push_back(new Block{});
}

template<typename T, size_t K>
void Deque<T, K>::push_back(const T& value) {
    if (tail == K) {
        expand(tail);
        tail = 0;
    }

    blocks.back()->data[tail++] = value;
}

template<typename T, size_t K>
void Deque<T, K>::push_front(const T& value) {
    if (head == 0) {
        expand(0);
        head = K - 1;
    } else {
        --head;
    }

    blocks.front()->data[head] = value;
}

template<typename T, size_t K>
void Deque<T, K>::pop_back() {
    if (tail == 0) {
        delete blocks.back();
        blocks.pop_back();
        tail = K;
    }

    --tail;
}

template<typename T, size_t K>
void Deque<T, K>::pop_front() {
    if (head == K - 1) {
        delete blocks.front();
        blocks.erase(blocks.begin());
        head = 0;
    } else {
        ++head;
    }
}

template<typename T, size_t K>
void Deque<T, K>::clear() {
    for (Block* block : blocks) {
        delete block;
    }
    blocks.clear();
    blocks.push_back(new Block{});
    head = 0;
    tail = 0;
}

template<typename T, size_t K>
size_t Deque<T, K>::size() const {
    return (blocks.size() - 1) * K + tail - head;
}

template<typename T, size_t K>
bool Deque<T, K>::empty() const {
    return size() == 0;
}

template<typename T, size_t K>
T& Deque<T, K>::operator[](size_t index) {
    size_t blockIndex = index / K;
    size_t elementIndex = index % K;
    return blocks[blockIndex]->data[elementIndex];
}

template<typename T, size_t K>
const T& Deque<T, K>::operator[](size_t index) const {
    size_t blockIndex = index / K;
    size_t elementIndex = index % K;
    return blocks[blockIndex]->data[elementIndex];
}

template<typename T, size_t K>
void Deque<T, K>::expand(size_t index) {
    blocks.insert(blocks.begin() + index / K, new Block{});
}

template<typename T, size_t K>
void Deque<T, K>::resize(size_t newCapacity) {
    if (newCapacity > capacity) {
        while (capacity < newCapacity) {
            capacity *= 2;
        }
        blocks.resize((capacity + K - 1) / K);
    }
}
