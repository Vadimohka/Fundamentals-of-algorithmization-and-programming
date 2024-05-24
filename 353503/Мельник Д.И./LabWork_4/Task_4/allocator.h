//
// Created by dmitry on 8.4.24.
//

#ifndef VECTOR_ALLOCATOR_H
#define VECTOR_ALLOCATOR_H

using uint32 = unsigned long int;

template <typename T>
class MyAllocator {
public:
    MyAllocator() = default;

    ~MyAllocator() = default;

    T *allocate(uint32 n) {
        return reinterpret_cast<T *>(::operator new(n * sizeof(T)));
    }

    void deallocate(T *p, uint32 n) { ::operator delete(p); }
    void construct(T* p, const T& t) { new(p) T(t); std::cout << "Allocator construct [" << p << "]" << std::endl; }
    void destroy(T* p) { p->~T(); std::cout << "Allocator destroy [" << p << "]" << std::endl; }
};


#endif //VECTOR_ALLOCATOR_H
