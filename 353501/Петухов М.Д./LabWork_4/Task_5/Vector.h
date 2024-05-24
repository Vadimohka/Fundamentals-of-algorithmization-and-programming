#ifndef VECTOR_H
#define VECTOR_H

#include "Iterator.h"
#include <initializer_list>

using namespace std;

template<typename T>
class Vector
{
private:
    T* arr = nullptr;
    size_t size = 0;
    size_t capacity = 0;
public:
    using iterator = Iterator<T>;
    using const_iterator = Iterator<const T>;
    using riterator = ReverseIter<T>;
public:
    void reserve(size_t n);
    void resize(size_t n, const T& value = T());
    void push_back(const T& value);
    void pop_back();

    void erase(iterator beg, iterator end);
    void erase(iterator tmp);
    void insert(size_t pos, const T& value);
    void assign(size_t n, T value);
    void swap(Vector<T> &v);

    T& operator [](size_t index) const;
    T& at(size_t index);
    T& back();
    T& front();
    T* data();

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    riterator rbegin();
    riterator rend();

    template<typename ... Args>
    void emplace(size_t pos, Args &&... args);
    template<typename ... Args>
    void emplace_back(Args &&... args);

    size_t Capacity() const;
    size_t Size();
    size_t max_size();
    bool empty();

    void clear();
};      

template<typename T>
template<typename... Types>
void Vector<T>::emplace(size_t pos, Types &&... args){
    T temp(args...);
    insert(pos, temp);
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace_back(Args &&... args) {
    T tmp(args...);
    push_back(tmp);
}

template<typename T>
typename Vector<T>::riterator Vector<T>::rbegin() {
    return riterator(arr + size);
}

template<typename T>
typename Vector<T>::riterator Vector<T>::rend() {
    return riterator(arr);
}

template<typename T>
void Vector<T>::erase(iterator tmp)
{
    erase(tmp, tmp + 1);
}

template<typename T>
void Vector<T>::swap(Vector<T> &v)
{
    std::swap(arr, v.arr);
    std::swap(size, v.size);
    std::swap(capacity, v.capacity);
}

template<typename T>
void Vector<T>::erase(Vector<T>::iterator beg, Vector<T>::iterator end)
{
    int it1 = beg.getIteratorAddress() - arr;
    int it2 = end.getIteratorAddress() - arr;

    for (auto i = it1; i <= it2; i++) {
        (arr + i)->~T();
        new(arr + i) T(arr[i + 1]);
    }

    size -= (it2 - it1);

}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const {
    return citerator(arr);
}

template<typename T>
bool Vector<T>::empty()
{
    return size == 0;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return iterator(arr);
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return iterator(arr + size);
}

template<typename T>
void Vector<T>::assign(size_t n, T value)
{
    clear();
    resize(n, value);
}

template<typename T>
T &Vector<T>::front() {
    return arr[0];
}

template<typename T>
size_t Vector<T>::max_size()
{
    return LLONG_MAX / sizeof(T);
}

template<typename T>
void Vector<T>::insert(size_t pos, const T& value){
    reserve(size + 1);
    size++;

    for(size_t i = size - 1; i > pos; i--){
        arr[i] = arr[i - 1];
    }

    arr[pos] = value; 
}


template<typename T>
T* Vector<T>::data(){
    return arr;
}

template<typename T>
T& Vector<T>::back(){
    return arr[size - 1];
}

template<typename T>
size_t Vector<T>::Capacity() const{
    return capacity;
}

template<typename T>
size_t Vector<T>::Size()
{
    return size;
}

template<typename T>
void Vector<T>::clear(){
    resize(0);
}

template<typename T> 
T& Vector<T>::operator [](size_t index) const{
    return arr[index];
}


template<typename T>
T& Vector<T>::at(size_t index){
    if(index > size){
        throw std::out_of_range("out of range exception");
    }
    return arr[index];
}


template<typename T>
void Vector<T>::resize(size_t n, const T& value){
    if(n > capacity)
        reserve(n);
    
    for(size_t i = size; i < n; i++){
        new (arr + i) T(value);
    }
    size = n;
};

template<typename T>
void Vector<T>::pop_back(){
    size--;
    (arr + size)->~T();
}

template<typename T>
void Vector<T>::push_back(const T& value)
{
    if (size >= capacity)
    {
        reserve(2 * size + 1);
    }
    new (arr + size) T(value);
    ++size;
}

template<typename T>
void Vector<T>::reserve(size_t Size)
{
    if (Size <= capacity)
        return;

    T *newData = new T[Size];
    auto dataMaxInd = std::min(Size, size);
    for(int i = 0; i < dataMaxInd; ++i){
        newData[i] = arr[i];
    }

    delete [] arr;
    arr = newData;
    size = dataMaxInd;
    capacity = Size;
}

#endif // VECTOR_H