#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <utility>

template <typename T> class MyVector {
public:
  MyVector(int r = 0) {
    reserved = r;
    if (reserved < 4)
      reserved = 4;

    count = 0;
    dynamicptr = (T *)malloc(sizeof(T) * reserved);
  };

  ~MyVector() {
    clear();
    free(dynamicptr);
  }

  T *data() { return dynamicptr; }

  T &at(int i) { return dynamicptr[i]; }
  const T &at(int i) const { return dynamicptr[i]; }

  T &operator[](int i) { return at(i); }
  const T &operator[](int i) const { return at(i); }

  T &front() { return at(0); }
  int size() const { return count; }
  bool isEmpty() const { return count == 0; }

  void reserve(int req) {
    if (req < reserved)
      return;
    while (req > reserved)
      reserved *= 2;

    T *oldptr = dynamicptr;

    dynamicptr = (T *)malloc(reserved * sizeof(T));

    for (int i = 0; i < count; i++) {
      new (&dynamicptr[i]) T(std::move(oldptr[i]));
      oldptr[i].~T();
    }

    free(oldptr);
  }

  void clear() {
    while (count > 0) {
      count--;
      dynamicptr[count].~T();
    }
  }

  void resize(int newsize) {
    reserve(newsize);
    while (count < newsize) {
      new (&dynamicptr[count]) T();
      count++;
    }
  }

  void swap(int a, int b) {
    T s(std::move(dynamicptr[a]));
    dynamicptr[a] = std::move(dynamicptr[b]);
    dynamicptr[b] = std::move(s);
  }

  void push_back(const T &el) {
    reserve(count + 1);
    new (&dynamicptr[count]) T(el);
    count++;
  }

  void pop_back() {
    count--;
    dynamicptr[count].~T();
  }

  int max_size() { return INT_MAX / sizeof(T); }

  void insert(int pos, const T &el) {
    if (pos == count)
      return push_back(el);

    reserve(count + 1);
    make_place_in(pos);
    dynamicptr[pos] = el;
  }

  void erase(int pos) {
    for (int i = pos; i < count - 1; i++) {
      dynamicptr[i] = std::move(dynamicptr[i + 1]);
    }
    count--;
    dynamicptr[pos].~T();
  }

  void emplace_back() {
    reserve(count + 1);
    new (&dynamicptr[count]) T();
    count++;
  }

  void emplace(int pos) {
    if (pos == count)
      return emplace_back();

    make_place_in(pos);
    dynamicptr[pos].~T();
    new (&dynamicptr[pos]) T();
  }

public:
  class Iterator {
    Iterator(MyVector<T> *vec, int pos = 0, int dir = 1)
        : vec(vec), pos(pos), dir(dir) {}
    friend class MyVector<T>;

  public:
    T &operator*() const { return vec->at(pos); };
    T *operator->() const { return &vec->at(pos); };

    bool operator==(const Iterator &i) const {
      return (vec == i.vec) && (i.pos == pos) && (i.dir == dir);
    };

    bool operator!=(const Iterator &i) const { return !operator==(i); };

    Iterator operator+(size_t n) { pos += n * dir; };
    Iterator operator++() {
      pos += dir;
      return *this;
    }
    Iterator operator++(int) {
      Iterator tmp = *this;
      pos += dir;
      return tmp;
    }

  private:
    MyVector<T> *vec;
    int pos;
    int dir;
  };

  Iterator begin() { return Iterator(this, 0); }
  Iterator end() { return Iterator(this, count); }

  Iterator rbegin() { return Iterator(this, count - 1, -1); }
  Iterator rend() { return Iterator(this, -1, -1); }

public:
  class ConstIterator {
    ConstIterator(const MyVector<T> *vec, int pos = 0, int dir = 1)
        : vec(vec), pos(pos), dir(dir) {}
    friend class MyVector<T>;

  public:
    const T &operator*() const { return vec->at(pos); };
    const T *operator->() const { return vec->at(pos); };

    bool operator==(const ConstIterator &i) const {
      return (vec == i.vec) && (i.pos == pos) && (i.dir == dir);
    };

    bool operator!=(const ConstIterator &i) const { return !operator==(i); };

    ConstIterator operator+(size_t n) { pos += n * dir; };
    ConstIterator operator++() {
      pos += dir;
      return *this;
    }
    ConstIterator operator++(int) {
      ConstIterator tmp = *this;
      pos += dir;
      return tmp;
    }

  private:
    const MyVector<T> *vec;
    int pos;
    int dir;
  };

  ConstIterator cbegin() { return ConstIterator(this, 0); }
  ConstIterator cend() { return ConstIterator(this, count); }

private:
  void make_place_in(int pos) {
    reserve(count + 1);
    new (&dynamicptr[count]) T(std::move(dynamicptr[count - 1]));
    count++;

    for (int i = count - 2; i > pos; i--) {
      dynamicptr[i] = std::move(dynamicptr[i - 1]);
    }
  }

  T *dynamicptr;
  size_t count;
  size_t reserved;
};
    