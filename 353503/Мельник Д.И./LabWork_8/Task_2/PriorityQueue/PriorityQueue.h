#ifndef B3EB3CB2_6B6F_4E27_AD07_8231A06A7D25
#define B3EB3CB2_6B6F_4E27_AD07_8231A06A7D25

#include <memory>

template <typename T> class PriorityQueue {
  static const size_t INITIAL_CAPACITY = 16;
  std::unique_ptr<T[]> data;
  size_t sizevar = 0;
  size_t capacity;

  size_t heapify(size_t i);
  void grow();
  bool is_full() { return sizevar + 1 == capacity; }

public:
  PriorityQueue();

  void clear();
  void push(T val);
  T pop();
  T &max();
  size_t size();
};

#endif /* B3EB3CB2_6B6F_4E27_AD07_8231A06A7D25 */
