

#include "PriorityQueue.h"

template <typename T> size_t PriorityQueue<T>::heapify(size_t i) {
  int max_ind = i;
  auto l = i * 2 + 1, r = i * 2 + 2;
  if (l < sizevar and data[l] > data[max_ind]) {
    max_ind = l;
  }
  if (r < sizevar and data[r] > data[max_ind]) {
    max_ind = r;
  }
  std::swap(data[max_ind], data[i]);
  return max_ind;
}

template <typename T> void PriorityQueue<T>::grow() {
  auto new_data = std::make_unique<T[]>(capacity * 2);
  for (int i = 0; i < sizevar; ++i) {
    new_data[i] = data[i];
  }

  data = std::move(new_data);
  capacity *= 2;
}

template <typename T>
PriorityQueue<T>::PriorityQueue()
    : data(std::make_unique<T[]>(INITIAL_CAPACITY)) {
  capacity = INITIAL_CAPACITY;
  sizevar = 0;
}

template <typename T> void PriorityQueue<T>::clear() {
  auto initial_data = std::make_unique<T[]>(INITIAL_CAPACITY);
  data = std::move(initial_data);

  sizevar = 0;
  capacity = INITIAL_CAPACITY;
}

template <typename T> void PriorityQueue<T>::push(T val) {
  if (is_full()) {
    grow();
  }

  data[sizevar] = val;
  ++sizevar;
  long cur = sizevar / 2 - 1;
  while (cur > 0 && heapify(cur) != cur) {
    cur = (cur - 1) / 2;
  }
  if (cur == 0) {
    heapify(0);
  }
}

template <typename T> T PriorityQueue<T>::pop() {
  T max = data[0];

  data[0] = data[sizevar - 1];
  --sizevar;

  auto cur = 0;
  size_t largest;
  while (cur < sizevar && (largest = heapify(cur)) != cur) {
    cur = largest;
  }
  return max;
}

template <typename T> T &PriorityQueue<T>::max() { return data[0]; }

template <typename T> size_t PriorityQueue<T>::size() { return sizevar; }

// bunch  of templates for static lib

template class PriorityQueue<int>;
template class PriorityQueue<long>;
template class PriorityQueue<long long>;