#include "vector.h"

template<typename T>
Vector<T>::Vector()
{
    data_ = nullptr;
    size_= 0;
    reserved_ = 0;
}

template<typename T>
Vector<T>::Vector(const Vector<T> &newV)
{
    size_ = newV.size_;
    reserved_ = newV.reserved_;
    data_ = new T[size_];
    for (size_t i = 0; i < size_; i++) {
        new(data_ + i) T(newV.data_[i]);
    }

}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list_) : size_(list_.size()), reserved_(list_.size())
{
    data_ = new T[size_];
    size_t i = 0;
    for (const T& element : list_) {
        data_[i++] = element;
    }
}


template<typename T>
Vector<T>::~Vector()
{
    for (size_t i = 0; i < size_; i++) {
        (data_ + i)->~T();
    }
    delete[] data_;
    data_ = nullptr;
    reserved_ = 0;
    size_ = 0;
}

template<typename T>
size_t Vector<T>::capacity()
{
    return reserved_;
}

template<typename T>
size_t Vector<T>::size()
{
    return size_;
}

template<typename T>
size_t Vector<T>::max_size()
{
    return LLONG_MAX / sizeof(T);
}

template<typename T>
void Vector<T>::insert(size_t pos, const T &t)
{
    reserve(size_ + 1);
    size_++;

    for(auto i = size_ - 1; i > pos; i--){
        data_[i] = data_[i - 1];
    }
    data_[pos] = t;
}

template<typename T>
void Vector<T>::assign(size_t n, T t)
{
    clear();
    resize(n, t);
}

template<typename T>
void Vector<T>::erase(iterator tmp)
{
    erase(tmp, tmp);
}

template<typename T>
void Vector<T>::erase(iterator beg, iterator end)
{
    int it1 = beg.base() - data_;
    int it2 = end.base() - data_;
    for (auto i = it1; i <= it2; i++) {
        (data_ + i)->~T();
        new(data_ + i) T(data_[i + 1]);
    }

    size_ = size_ - (it2 - it1);

}

template<typename T>
T &Vector<T>::operator[](size_t n) const
{
    return data_[n];
}

template<typename T>
Vector<T>::Vector(size_t n) {
    reserve(n);
    for (size_t i = 0; i < n; i++) {
        new(data_ + i) T();
    }
}

template<typename T>
void Vector<T>::reserve(size_t size)
{
    if (size <= reserved_)
        return;

    T *newData = new T[size];
    auto dataMaxInd = std::min(size, size_);
    for(int i = 0; i < dataMaxInd; ++i){
        newData[i] = data_[i];
    }

    delete [] data_;
    data_ = newData;
    size_ = dataMaxInd;
    reserved_ = size;
}

template<typename T>
void Vector<T>::resize(size_t size, T temp) {
    if (size > reserved_)
        reserve(size);

    for (size_t i = size_; i < size; i++) {
        new(data_ + i) T(temp);
    }
    for (size_t i = size; i < size_; i++) {
        (data_ + i)->~T();
    }
    size_ = size;
}

template<typename T>
void Vector<T>::push_back(T temp)
{
    if (size_ >= reserved_)
    {
        reserve(size_ + 1);
    }
    new (data_ + size_) T(temp);
    ++size_;
}

template<typename T>
void Vector<T>::pop_back()
{
    if(size_ == 0){
        return;
    }
    (data_ + size_ - 1)->~T();
    size_--;
}

template<typename T>
bool Vector<T>::empty()
{
    return size_ == 0;
}

template<typename T>
void Vector<T>::clear()
{
    resize(0);
}


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
