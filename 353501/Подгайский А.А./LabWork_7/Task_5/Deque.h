#ifndef F111052C_DD46_4E1D_9785_CCA265D7B53D
#define F111052C_DD46_4E1D_9785_CCA265D7B53D

#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>

template <typename T> class Deque {

  static const size_t BLOCK_SIZE = 1024;
  static const int GROW_FACTOR = 2;

  struct deq_idx {
    size_t block;
    size_t idx;

    bool operator==(deq_idx &other) {
      return block == other.block && idx == other.idx;
    }
  };

private:
  T **data;

  size_t capacity; // capacity of arrary of block ptrs
  deq_idx first;
  size_t size_var; // total elements in deque

private:
  void grow() {
    size_t new_size = capacity * GROW_FACTOR;
    T **new_data = new T *[new_size];

    auto used_blocks = size_var / BLOCK_SIZE;

    size_t j = 0;
    size_t i = first.block;
    while (j <= used_blocks) {
      new_data[j] = data[i];
      i = (i + 1) % capacity;
      ++j;
    }
    for (; j < new_size; ++j) {
      new_data[j] = reinterpret_cast<T *>(new uint8_t[BLOCK_SIZE * sizeof(T)]);
    }

    delete[] data;
    data = new_data;
    capacity = new_size;
    first.block = 0;
  }

  bool is_full() { return size_var == capacity * BLOCK_SIZE - 1; }

  deq_idx idx_at(size_t i) const {
    auto total_index = (first.block * BLOCK_SIZE + first.idx + i);
    auto qr = std::lldiv(total_index, BLOCK_SIZE);
    return {(size_t)qr.quot % capacity, (size_t)qr.rem};
  }

public:
  Deque() {
    data = new T *[2];
    for (int i = 0; i < 2; ++i) {
      data[i] = reinterpret_cast<T *>(new uint8_t[sizeof(T) * BLOCK_SIZE]);
    }
    capacity = 2;
    size_var = 0;
    first.block = 0;
    first.idx = 0;
  }

  ~Deque() {
    for (int i = 0; i < capacity; ++i) {
      delete[] data[i];
    }
    delete[] data;
  }

  void push_back(const T &t) {
    if (is_full()) {
      grow();
    }

    ++size_var;
    auto new_idx = idx_at(size_var - 1);
    new (&data[new_idx.block][new_idx.idx]) T(t);
  }

  void push_front(const T &t) {
    if (is_full()) {
      grow();
    }

    ++size_var;
    --first.idx;
    if (first.idx == (size_t)(-1)) {
      first.idx = BLOCK_SIZE - 1;
      --first.block;
    }
    if (first.block == (size_t)(-1)) {
      first.block = capacity - 1;
    }

    new (&data[first.block][first.idx]) T(t);
  }

  void pop_back() {
    auto last = idx_at(size_var - 1);
    data[last.block][last.idx].~T();
    --size_var;
  }

  void pop_front() {
    data[first.block][first.idx].~T();

    --size_var;
    ++first.idx;
    if (first.idx == BLOCK_SIZE) {
      first.idx = 0;
      first.block++;
    }
    if (first.block == capacity) {
      first.block = 0;
      first.idx = 0;
    }
  }

  const T &front() const { return data[first.block][first.idx]; }
  const T &back() const { return operator[](size_var - 1); }

  T &operator[](size_t idx) const {
    auto real_idx = idx_at(idx);
    return data[real_idx.block][real_idx.idx];
  }

  T &operator[](size_t idx) {
    auto real_idx = idx_at(idx);
    return data[real_idx.block][real_idx.idx];
  }

  size_t size() const { return size_var; }
  bool empty() const { return size_var == 0; }

  class iterator {
    friend class Deque<T>;
    Deque<T> *container;
    long long idx;

    iterator(Deque<T> *parent, size_t index) : container(parent), idx(index) {}

  public:
    iterator &operator++() {
      ++idx;
      return *this;
    }

    iterator operator++(int) {
      iterator tmp = *this;
      idx++;
      return tmp;
    }

    iterator &operator--() {
      --idx;
      return *this;
    }

    iterator operator--(int) {
      iterator tmp = *this;
      idx--;
      return tmp;
    }

    T &operator*() {
      deq_idx internal_idx = container->idx_at(idx);
      return container->data[internal_idx.block][internal_idx.idx];
    }
    bool operator==(const iterator &other) { return this->idx == other.idx; }
    bool operator!=(const iterator &other) { return this->idx != other.idx; }
  };

  iterator begin() { return iterator(this, 0); }
  iterator end() { return iterator(this, size_var); }
};

#endif /* F111052C_DD46_4E1D_9785_CCA265D7B53D */
