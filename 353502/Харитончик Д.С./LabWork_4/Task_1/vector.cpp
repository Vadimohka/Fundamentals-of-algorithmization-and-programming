#include <iostream>
#include <stdexcept>

template <typename T>
class Vector{
private:
    T* data;
    size_t capacity;
    size_t size;

public:
    Vector() : data(nullptr), capacity(0), size(0) {}

    Vector(size_t initial_capacity) : capacity(initial_capacity), size(0) {
        data = new T[capacity];
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    size_t getSize() const {
        return size;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

private:
    void resize() {
        if (capacity == 0) {
            capacity = 1;
        } else {
            capacity *= 2;
        }
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};
