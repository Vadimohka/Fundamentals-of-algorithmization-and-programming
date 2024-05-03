#include "my_iterator.h"

template<typename T>
T &My_iterator<T>::operator*() const {
    return *ptr;
}

template<typename T>
T *My_iterator<T>::operator->() const {
    return ptr;
}

template<typename T>
My_iterator<T> My_iterator<T>::operator++(int) {
    My_iterator temp = *this;
    ++ptr;
    return temp;
}

template<typename T>
My_iterator<T> &My_iterator<T>::operator++() {
    ++ptr;
    return *this;
}

template<typename T>
My_iterator<T> &My_iterator<T>::operator--() {
    --ptr;
    return *this;
}

template<typename T>
My_iterator<T> &My_iterator<T>::operator--(int) {
    My_iterator temp = *this;
    --ptr;
    return temp;
}

template<typename T>
My_iterator<T> My_iterator<T>::operator+(int n) const
{
    return My_iterator(ptr + n);
}

template<typename T>
My_iterator<T> My_iterator<T>::operator-(int n) const
{
    return My_iterator(ptr - n);
}

template<typename T>
My_iterator<T>& My_iterator<T>::operator+=(int n) {
    ptr += n;
    return *this;
}

template<typename T>
My_iterator<T>& My_iterator<T>::operator-=(int n) {
    ptr -= n;
    return *this;
}

template<typename T>
T &My_iterator<T>::operator[](int n) const
{
    return ptr[n];
}

template<typename T>
bool My_iterator<T>::operator==(const My_iterator &other) const
{
    return ptr == other.ptr;
}

template<typename T>
bool My_iterator<T>::operator!=(const My_iterator &other) const {
    return ptr != other.ptr;
}
