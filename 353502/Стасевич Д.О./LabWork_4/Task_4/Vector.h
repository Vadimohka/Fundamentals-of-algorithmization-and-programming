#ifndef TASK4_VECTOR_H
#define TASK4_VECTOR_H

#include "Iterator.h"
#include "ReverseIterator.h"

#include <cstdint>
#include <initializer_list>

#include <QDebug>

template<typename T>
class Vector {
    using b_iterator = Iterator<T>;
    using r_iterator = ReverseIterator<T>;
    using c_iterator = Iterator<const T>;
private:
    T* arr = nullptr;
    size_t sz = 0;
    size_t cap = 0;

public:

    Vector() {
        sz = 0;
        cap = 0;
        arr = nullptr;
    }

    Vector(std::initializer_list<T> l)
    {
        reserve(l.size());
        sz = l.size();
        arr = reinterpret_cast<T *>(new int8_t[sz * sizeof(T)]);
        auto listIt = l.begin();
        for (size_t i = 0; i < sz; i++)
        {
            T tmp = *listIt;

            new(arr + i) T(tmp);
            listIt ++;
        }
    }

    Vector(size_t n, const T& value = T())
    {
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
    }

    ~Vector()
    {
        for(int i = 0; i < sz; i ++)
        {
            (arr + i)->~T();
        }
        arr = nullptr;
        sz = 0;
        cap = 0;
    }

    T &operator[](size_t n) const
    {
        return arr[n];
    }

    b_iterator begin() {
        if(sz == 0)
        {
            return end();
        }
        return b_iterator(arr);
    }

    b_iterator end() {
        return b_iterator (arr + sz);
    }

    c_iterator cbegin() {
        return c_iterator (arr);
    }

    r_iterator rend() {
        return r_iterator(arr);
    }

    r_iterator rbegin() {
        return r_iterator(arr + sz - 1);
    }

    size_t size() const
    {
        return sz;
    }

    size_t capacity() const
    {
        return cap;
    }

    bool empty(){
        return (sz == 0);
    }

    void reserve(size_t n) {
        if(n <= cap)
            return;
        T *new_arr = reinterpret_cast<T *>(new int8_t[n * sizeof(T)]);
        for (int i = 0; i < sz; ++i) {
            try {
                new(new_arr + i) T(arr[i]);
            }
            catch (...){
                throw "incorrect constructor";
            }
        }
        for(int i = 0; i < sz; i ++)
            (arr + i)->~T();
        delete[]reinterpret_cast<int8_t *>(arr);
        arr = new_arr;
        cap = n;
    }

    void resize(size_t n, const T& value = T()){
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
            (arr + i)->~T();
        }
        sz = n;
    }

    size_t max_size() const{
        return INTMAX_MAX / sizeof(T);
    }

    void push_back(const T& value)
    {
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

    void pop_back()
    {
        if(sz == 0)
            return;
        (arr + sz - 1)->~T();
        sz --;
    }

    void clear()
    {
        resize(0);
    }

    void assign(size_t count, const T& value)
    {
        clear();
        resize(count, value);
    }

    void insert(c_iterator pos, T const &value) {
        if(sz + 1 > cap)
            reserve(2 * sz + 1);
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

    void insert(b_iterator pos, size_t count, const T &value) {
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

    void insert(b_iterator pos, T &&value) {
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

    template<typename ... Args>
    void emplace(c_iterator pos, Args &&... args)
    {
        T tmp(args...);
        insert(pos, tmp);
    }

    template<typename ... Args>
    void emplace_back(Args &&... args)
    {
        T tmp(args...);
        push_back(tmp);
    }

    void erase(b_iterator first, b_iterator lst) {
        int f = first.base() - arr;
        int s = lst.base() - arr;
        if(f >= s)
            throw "incorrect data for erase";
        if(s > sz)
            s = sz;

        for(int i = f; i < s; i ++)
        {
            (arr + i)->~T();
            qDebug() << "delete " << i << '\n';
            if(i + (s - f) < sz) {
                try {
                    qDebug() << "create " << i << " using" << i + s - i;
                    new(arr + i) T((arr[i + s - f]));
                }
                catch (...) {
                    throw "mistake copy constructor";
                }
            }
        }
        for(int i = s; i < sz; i ++)
        {
            (arr + i)->~T();
            qDebug() << "delete " << i << '\n';
            if(i + (s - f) < sz) {
                try {
                    new(arr + i) T((arr[i + s - f]));
                    qDebug() << "create " << i << " using" << i + s - i;
                }
                catch (...) {
                    throw "mistake copy constructor";
                }
            }
        }
        sz = sz - (s - f);
    }

    void erase(b_iterator pos) {
        if(sz == 0)
            return;
        erase(pos, pos + 1);
    }

    void swap(Vector<T>& b)
    {
        auto temp = arr;
        this->arr = b.arr;
        b.arr = temp;
        size_t temp2 = this->sz;
        this->sz = b.sz;
        b.sz = temp2;
        temp2 = this->cap;
        this->cap = b.cap;
        b.cap = temp2;
    }

    T &at(size_t pos)
    {
        if(pos > sz)
            throw "out of range";
        return arr[pos];
    }

    T &back()
    {
        return arr[sz - 1];
    }

    T& front()
    {
        return arr[0];
    }

    T* data()
    {
        if(sz == 0)
            return nullptr;
        return arr;
    }
};
/*
 * data - pointer to the first element in array
 */


#endif //TASK4_VECTOR_H
