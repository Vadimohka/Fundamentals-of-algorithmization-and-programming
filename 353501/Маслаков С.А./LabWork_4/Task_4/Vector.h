
#ifndef TASK4_VECTOR_H
#define TASK4_VECTOR_H

//#include <cstddef>
#include "iterator.h"
#include <cstddef>
#include <stdexcept>

class iterator;

template<typename T>
class Vector{
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
    using iterator = Iterator<T>;
    using rIterator = ReverseIterator<T>;
public:
    Vector(){
        reAlloc(2);
    }
    void reAlloc(size_t newCapacity){
        if(size > newCapacity) size = newCapacity;
        T* newVector = new T[newCapacity];
        for(size_t i = 0;i < size;++i){
            newVector[i] = std::move(data[i]);
            delete data[i];
        }
        delete data;
        data = newVector;
        capacity = newCapacity;
    }
    void pushBack(const T& elem){
        if(size >= capacity) reAlloc(capacity * 1,5);
        data[size++] = std::move(elem);
    }
    size_t Size(){
        return  size;
    }
    T& operator[](size_t index){
        if(index >= size){
            throw std::out_of_range("Index out if range");
        }
        return data[index];
    }
    template<typename ... Args>
    T& EmplaceBack(Args&&...args){
        if(size >= capacity) reAlloc(capacity * 1,5);
        new(&data[size]) T(std::forward<Args>(args) ...);
        //data[size] = T(std::forward<Args>(args) ...);
        return data[size++];
    }
    ~Vector(){
        delete[] data;
        size = 0;
    }
    void PopBack(){
        size--;
        data[size].~T();
    }
    void Clear(){
        for(int i = 0;i < size;++i){
            data[i].~T();
        }
        size = 0;
    }
    void swap(Vector<T> &to)
    {
        std::swap(data, to._array);
        std::swap(size, to._size);
        std::swap(capacity, to.capacity());
    }
    void insert(Vector::iterator pos, T const &temp)
    {
        unsigned long long _pos = (pos).base() - data;
        reAlloc(size + 1);
        for (unsigned long long i = size; i > _pos; --i)
        {
            new (data + i) T(data[i - 1]);
            (data + i - 1)->~T();
        }
        new(data + _pos) T(temp);
        ++data;
    }
    void assign(unsigned long long n, T temp)
    {
        Clear();
        resize(n, temp);
    }
    void erase(Vector<T>::iterator begin, Vector<T>::iterator end)
    {
        unsigned long long j = begin.base() - data;
        unsigned long long k = end.base() - data;
        for (unsigned long long i = j; i < k; ++i)
        {
            (data + i)->~T();
            new (data + i) T(data[i + 1]);
        }
        size -= k - j;
    }

    T &back()
    {
        return data[size - 1];
    }

    T &front()
    {
        return data;
    }

    T &at(unsigned long long place)
    {
        if (place > size)
        {
            throw std::out_of_range("");
        }
        try
        {
            return data[place];
        } catch (...)
        {
            throw std::out_of_range("");
        }
    }
    unsigned long long mem_size()
    {
        return size;
    }
    void reserve(unsigned long long size)
    {
        if (size <= capacity)
        {
            return;
        }
        T *temp = new T[size];
        for (int i = 0; i < size; ++i)
        {
            new (temp + i) T(data[i]);
            (data + i)->~T();
        }
        delete[] data;
        data = temp;
        capacity = size;
    }

    Vector<T>::iterator begin()
    {
        return iterator(data);
    }

    Vector<T>::iterator end()
    {
        return iterator(data + size);
    }

    Vector<T>::rIterator revers_begin()
    {
        return rIterator(data);
    }

    Vector<T>::rIterator reverse_end()
    {
        return rIterator(data + size);
    }
};
#endif //TASK4_VECTOR_H
