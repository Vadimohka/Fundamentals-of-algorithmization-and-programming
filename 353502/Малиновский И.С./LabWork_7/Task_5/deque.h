#ifndef DEQUE_H
#define DEQUE_H

#include <vector>
#include <memory>

template<typename T, size_t K = 16>
class Deque {
public:
    Deque();
    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    void clear();
    size_t size() const;
    bool empty() const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    void resize(size_t newCapacity);

private:
    struct Block {
        T data[K];
        Block* prev;
        Block* next;
    };
    std::vector<Block*> blocks;
    size_t head;
    size_t tail;
    size_t capacity;
    void expand(size_t index); // Объявление метода expand
};



#include "deque.cpp"

#endif // DEQUE_H
