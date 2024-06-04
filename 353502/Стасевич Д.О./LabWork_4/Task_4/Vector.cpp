#include <algorithm>
#include "Vector.h"
/*
template<typename T>
Vector<T>::Vector() {
    arr = nullptr;
    sz = 0;
    cap = 0;
}

template<typename T>
Vector<T>::~Vector() {
    clear();
}

template<typename T>
Vector<T>::Vector(size_t n, const T &value) {
    reserve(n);
    sz = n;
    for(int i = 0; i < n; i ++)
    {
        try
        {
            new(arr + i) T(value);
        }
        catch (...)
        {
            throw "bad copy constructor";
        }
    }
}*/
/*
template<typename T>
Vector<T>::Vector(size_t n) {
    reserve(n);
    for(int i = 0; i < n; i ++)
    {
        try
        {
            new(arr + i) T();
        }
        catch (...)
        {
            throw "bad copy constructor";
        }
    }
}



/*
template<typename T>
Vector<T>::Vector(size_t n) {
    reserve(n);
    for (size_t i = 0; i < n; i++) {
        new(arr + i) T();
    }
}*/
/*
template<typename T>
Vector<T>::Vector(Vector<T> const &tmp_) {
    sz = tmp_.size_;
    cap = tmp_.capacity_;
    arr = reinterpret_cast<T*>(new int8_t[sz * sizeof(T)]);
    for (size_t i = 0; i < sz; i++) {
        new (arr + i) T(tmp_[i]);
    }
}


template<typename T>
Vector<T>::Vector(std::initializer_list<T> l) :
        sz(l.size()),
        cap(l.size())
{
    arr = reinterpret_cast<T *>(new int8_t[sz * sizeof(T)]);
    auto listIt = l.begin();
    for (size_t i = 0; i < sz; i++, listIt++) {
        T tmp = *listIt;
        new(arr + i) T(std::move(tmp));
    }
}

template<typename T>
Vector<T>::~Vector() {
    for (size_t i = 0; i < sz; i++) {
        (arr + i)->~T();
    }
    // delete[] reinterpret_cast<int8_t *>(arr_);
    arr = nullptr;
    cap = 0;
    sz = 0;
}
*/
/*

template<typename T>
size_t Vector<T>::size() const {
    return sz;
}

template<typename T>
size_t Vector<T>::capacity() const {
    return cap;
}

template<typename T>
bool Vector<T>::empty() {
    return (sz == 0);
}

template<typename T>
void Vector<T>::reserve(size_t n) {
    if(n <= cap)
        return;
    T *new_arr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);
    for (size_t i = 0; i < sz; ++i) {
        try {
            new(new_arr + i) T(arr[i]);
        }
        catch (...){
            throw "incorrect constructor";
        }
    }
    for(size_t i = 0; i < sz; i ++)
    {
        (arr[i])->~T();
    }
    delete[]reinterpret_cast<int8_t *> (arr);
    arr = new_arr;
    cap = n;
}

template<typename T>
void Vector<T>::resize(size_t n, const T &value) {
    if(n > cap)
        reserve(n);

    for(size_t i = sz; i < n; i ++)
    {
        try {
            new(arr + i) T(value);
        }
        catch (...){
            throw "incorrect constructor";
        }
    }

    for(size_t i = n; i < sz; i ++)
    {
        (arr[i])->~T();
    }
    sz = n;
}

template<typename T>
void Vector<T>::push_pack(const T &value) {
    if(cap == sz)
        reserve(sz * 2 + 1);
    try {
        new(arr + sz) T(value);
    }
    catch (...){
        throw "incorrect constructor";
    }
    sz ++;
}

template<typename T>
void Vector<T>::pop_back() {
    if(sz == 0)
        return;
    (arr + sz - 1)->~T();
    sz --;
}

template<typename T>
void Vector<T>::clear() {
    resize(0);
}

template<typename T>
void Vector<T>::assign(size_t count, const T &value) {
    clear();
    resize(count, value);
}

template<typename T>
T &Vector<T>::at(size_t pos) { ///
    if(pos > sz)
        throw "out of range";
    return arr[pos];
}

template<typename T>
T &Vector<T>::back() {
    return arr[sz - 1];
}

template<typename T>
typename Vector<T>::b_iterator Vector<T>::begin() {
    if(sz == 0)
    {
        return end();
    }
    return b_iterator(arr);
}

template<typename T>
typename Vector<T>::b_iterator Vector<T>::end() {
    return b_iterator (arr + sz);
}

template<typename T>
typename Vector<T>::c_iterator Vector<T>::cbegin() {
    return c_iterator (arr);
}

template<typename T>
typename Vector<T>::r_iterator Vector<T>::rend() {
    return Vector::r_iterator(arr);
}

template<typename T>
typename Vector<T>::r_iterator Vector<T>::rbegin() {
    return Vector::r_iterator(arr + sz - 1);
}


template<typename T>
T *Vector<T>::data() {
    if(sz == 0)
        return nullptr;
    return arr;
}

template<typename T>
void Vector<T>::insert(Vector::c_iterator pos, const T &value) {
    if(sz + 1 > cap)
        reserve(2 * sz + 1);
    // 0 1 2 3 4 5
    //     -
    // 0 1 (2) - 3 4 5 6

    // convert iterator to index
    size_t p = pos.base() - arr;

    for(int i = sz; i > p; i --)
    {
        try {
            new (arr + i) T(arr[i - 1]);
            (arr + i - 1)->~T();
        }
        catch (...)
        {
            throw "fail copy constructor";
        }
    }
    try {
        new (arr + p) T(value);
    }
    catch (...)
    {
        throw "fail copy constructor";
    }
    sz ++;
}

template<typename T>
void Vector<T>::insert(Vector::c_iterator pos, size_t count, const T &value) {
    while(sz + count > cap)
        reserve(cap * 2 + 1);

    size_t p = pos.base() - arr;

    // 0 1 2  3 4  5
    //     |
    // 0 1 (2 3 4) 5 6 7 8
    // p = 2, count = 3, sz = 6

    for(size_t i = sz + count - 1; i >= p + count; i --)
    {
        try {
            new (arr + i) T(arr[i - count]);
            (arr + i - count)->~T();
        }
        catch (...)
        {
            throw "fail copy constructor";
        }
    }
    for(size_t i = p; i < p + count; i ++)
    {
        try {
            new(arr + i) T(value);
        }
        catch (...)
        {
            throw "fail copy constructor";
        }
    }
    sz = sz + count;
}

template<typename T>
void Vector<T>::insert(Vector::c_iterator pos, T &&value) {
    if(sz + 1 > cap)
        reserve(2 * sz + 1);
    // 0 1 2 3 4 5
    //     -
    // 0 1 (2) - 3 4 5 6

    // convert iterator to index
    size_t p = pos.base() - arr;

    for(int i = sz; i > p; i --)
    {
        try {
            new (arr + i) T(arr[i - 1]);
            (arr + i - 1)->~T();
        }
        catch (...)
        {
            throw "fail copy constructor";
        }
    }
    try {
        new (arr + p) T(value);
    }
    catch (...)
    {
        throw "fail copy constructor";
    }
    sz ++;
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace(Vector::c_iterator pos, Args &&... args) {
    // same as insert
    T tmp(args...);
    insert(pos, tmp);
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace_back(Args &&... args) {
    // insert in end
    T tmp(args...);
    push_pack(tmp);
}

template<typename T>
void Vector<T>::erase(Vector::b_iterator first, Vector::b_iterator lst) {
    int f = first.base() - arr;
    int s = lst.base() - arr;
    if(f >= s)
        throw "incorrect data for erase";
    if(s > sz)
        s = sz;
    // 2 - 4 : 2, 3
    for(int i = f; i < s; i ++)
    {
        (arr + i)->~T();
        if(i < s - 1 || s < sz) {
            try {
                new(arr + i) T((arr[i + 1]));
            }
            catch (...) {
                throw "mistake copy constructor";
            }
        }
    }
    sz = sz - (s - f);
}

template<typename T>
void Vector<T>::erase(Vector::b_iterator pos) {
    if(sz == 0)
        return;
    erase(pos, pos + 1);
}

template<typename T>
T &Vector<T>::front() {
    return arr[0];
}

template<typename T>
size_t Vector<T>::max_size() const {
    return INTMAX_MAX / sizeof(T);
}

template<typename T>
void Vector<T>::swap(Vector<T> &b) {
    auto temp = arr;
    this->arr = b.arr;
    b.arr = temp;
    size_t temp2 = this->sz;
    this->sz = b.sz;
    b.sz = this->sz;
    temp2 = this->cap;
    this->cap = b.cap;
    b.cap = this->cap;
}*/