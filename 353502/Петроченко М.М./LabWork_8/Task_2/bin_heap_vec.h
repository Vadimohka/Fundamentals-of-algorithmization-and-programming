#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

template <typename T>
class VecBinHeap {
    std::vector<T> arr;

    void heapify(size_t index) {
        size_t left_index = 2 * index + 1;
        size_t right_index = 2 * index + 2;
        size_t largest = index;
        if (left_index < this->arr.size() &&
            this->arr[left_index] > this->arr[largest]) {
            largest = left_index;
        }
        if (right_index < this->arr.size() &&
            this->arr[right_index] > this->arr[largest]) {
            largest = right_index;
        }
        if (largest != index) {
            std::swap(this->arr[largest], this->arr[index]);
            this->heapify(largest);
        }
    }

    void heapify_up(size_t index) {
        if (index <= 0) {
            return;
        }
        int parent = 0;
        if (index % 2 == 0) {
            parent = (index - 2) / 2;
        } else {
            parent = (index - 1) / 2;
        }
        if (parent >= 0 && parent < this->arr.size()) {
            if (this->arr[parent] >= this->arr[index]) {
                return;
            } else {
                std::swap(this->arr[parent], this->arr[index]);
                this->heapify_up(parent);
            }
        }
    }

    void build_heap() {
        for (size_t i = this->arr.size() / 2; i >= 0; ++i) {
            this->heapify(i);
        }
    }

   public:
    int64_t find(const T& elem) {
        for (size_t i = 0; i < this->arr.size(); ++i) {
            if (elem == this->arr[i]) {
                return i;
            }
        }
        return -1;
    }

    void insert(const T& elem) {
        size_t prev_len = this->arr.size();
        this->arr.push_back(elem);
        this->heapify_up(prev_len);
    }

    void erase(const T& elem) {
        int64_t index = this->find(elem);
        if (index != -1) {
            std::swap(this->arr[this->arr.size() - 1], this->arr[index]);
        }
    }

    void print() {
        for (auto& elem : this->arr) {
            std::cout << elem << " ";
        }
        std::cout << '\n';
    }
};
