#ifndef VECTOR_ITERATOR_H
#define VECTOR_ITERATOR_H

template<typename T>
class Vector;

template<typename T>
class VectorIterator {
public:
    VectorIterator(T* ptr = nullptr) : _ptr(ptr) {}

    T& operator*() { return *_ptr; }
    T* operator->() { return _ptr; }

    VectorIterator& operator++() { ++_ptr; return *this; }
    VectorIterator operator++(int) { VectorIterator tmp = *this; ++_ptr; return tmp; }

    bool operator==(const VectorIterator& other) const { return _ptr == other._ptr; }
    bool operator!=(const VectorIterator& other) const { return _ptr != other._ptr; }

private:
    T* _ptr;

    friend class Vector<T>;
};

#endif // VECTOR_ITERATOR_H
