#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T>
class Queue {
public:
    void enqueue(const T& value) {
        data.push_back(value);
    }

    void enqueue2(const T& value) {
        data2.push_back(value);
    }

    T dequeue() {
        if (data.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T value = data.front();
        data.erase(data.begin());
        return value;
    }

    void findMax() {
        if (data.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        auto maxEl = std::max_element(data.begin(), data.end());
        T maxValue = *maxEl;
        data.insert(++maxEl, data2.begin(), data2.end());
    }

    typename std::vector<T>::iterator begin() {
        return data.begin();
    }

    typename std::vector<T>::iterator end() {
        return data.end();
    }

    void clear() {
        if (!data.empty()) data.clear();
    }

    void clear2() {
        if (!data2.empty()) data2.clear();
    }

private:
    std::vector<T> data;
    std::vector<T> data2;
};

#endif // QUEUE_H
