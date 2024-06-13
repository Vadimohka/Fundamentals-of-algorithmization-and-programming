#ifndef VECTORALLOCATOR_H
#define VECTORALLOCATOR_H
#include <cstddef>


template<typename T>
class VectorAllocator{

public:

    T* allocate(size_t count) const {
        return static_cast<T*>(::operator new(count * sizeof(T)));
    }

    void deallocate(T* ptr, size_t size){
        ::operator delete(ptr);
    }

    template<typename ...Args>
    void constructor(T*ptr, const Args& ...args){
        new(ptr) T(args...);
    }

    void destroy(T* ptr){
        ptr->~T();
    }

};

#endif // VECTORALLOCATOR_H
