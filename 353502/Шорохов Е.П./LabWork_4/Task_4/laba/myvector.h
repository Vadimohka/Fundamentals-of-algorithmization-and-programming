#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>

//I am booored
template<typename T, typename Alloc = std::allocator<T>>
class myVector
{
    using alloc_traits = std::allocator_traits<Alloc>;

public:
    class Iterator
    {
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;
        using iterator_category = std::random_access_iterator_tag;

    public:
        Iterator()
            : v(nullptr)
            , i(0)
        {}
        Iterator(myVector<T> *_v, size_t _i)
            : v(_v)
            , i(_i)
        {}

        reference operator*() const { return (*v)[i]; }

        const pointer operator->() const { return &((*v)[i]); }

        reference operator[](size_t n) const { return (*v)[i + n]; }

        Iterator &operator++()
        {
            i++;
            return *this;
        }

        Iterator &operator--()
        {
            i--;
            return *this;
        }

        const Iterator operator++(int)
        {
            Iterator r(*this);
            ++i;
            return r;
        }

        const Iterator operator--(int)
        {
            Iterator r(*this);
            --i;
            return r;
        }

        Iterator &operator+(size_t n)
        {
            Iterator r(*this);

            r.i += n;
            return r;
        }
        Iterator &operator-(size_t n)
        {
            Iterator r(*this);

            r.i -= n;
            return r;
        }

        bool operator<(Iterator const &r) const { return i < r.i; }

        bool operator!=(Iterator const &r) const { return i != r.i; }

    private:
        myVector<T> *v;
        size_t i;
    };

    myVector() { arr = alloc_traits::allocate(alloc, cap); }
    myVector(const myVector<T, Alloc> &obj)
    {
        reserve(obj.cap);
        resize(obj.sz);

        try {
            std::uninitialized_copy(obj.arr, obj.arr + obj.sz, arr);
        } catch (...) {
            throw;
        }
    }
    myVector(myVector<T, Alloc> &&obj) noexcept
        : arr(obj.arr)
        , sz(obj.sz)
        , cap(obj.cap)
    {
        obj.arr = nullptr;
    }
    void assign(size_t size, const T &value) { resize(size, value); }
    T &at(size_t pos)
    {
        if (pos >= sz || pos < 0) {
            throw std::out_of_range("Index is not in range [0,sz)");
        }

        return arr[pos];
    }
    T &back() { return arr[sz - 1]; }
    Iterator begin() { return Iterator(this, 0); }
    Iterator end() { return Iterator(this, sz); }
    size_t capacity() { return cap; }
    void clear() { sz = 0; }
    T *data();
    template<typename... Args>
    void emplace(size_t pos, Args &&...args)
    {
        T *newarr = alloc_traits::allocate(alloc, sz + 1);

        try {
            std::uninitialized_move(arr, arr + pos + 1, newarr);
            alloc_traits::construct(alloc, newarr + pos + 1, std::forward<Args>(args)...);
            std::uninitialized_move(arr + pos + 1, arr + sz, newarr + pos + 2);
        } catch (...) {
            alloc_traits::deallocate(alloc, newarr, sz + 1);
            throw;
        }

        alloc_traits::deallocate(alloc, arr, sz);
        arr = newarr;
        ++sz;
    }
    template<typename... Args>
    void emplace_back(Args &&...args)
    {
        if (sz == cap) {
            reserve(2 * cap);
        }

        alloc_traits::construct(alloc, arr + sz, std::forward<Args>(args)...);
        ++sz;
    }
    bool empty() { return sz == 0; }
    void erase(size_t pos_l, size_t pos_r)
    {
        try {
            std::uninitialized_move(arr + pos_r + 1, arr + sz, arr + pos_l);
        } catch (...) {
            throw;
        }

        sz -= pos_r - pos_l + 1;
    }
    T &front();
    void insert(size_t pos, const T &value)
    {
        T *newarr = alloc_traits::allocate(alloc, sz + 1);

        try {
            std::uninitialized_move(arr, arr + pos + 1, newarr);

            alloc_traits::construct(alloc, newarr + pos + 1, value);

            std::uninitialized_move(arr + pos + 1, arr + sz, newarr + pos + 2);
        } catch (...) {
            alloc_traits::deallocate(alloc, newarr, sz + 1);
            throw;
        }

        alloc_traits::deallocate(alloc, arr, sz);
        arr = newarr;
        ++sz;
    }
    size_t max_size() { return std::numeric_limits<T>::max(); }
    void pop_back() { --sz; }
    void push_back(const T &value)
    {
        if (sz == cap) {
            reserve(2 * cap);
        }

        alloc_traits::construct(alloc, arr + sz, value);
        ++sz;
    }
    void push_back(T &&value)
    {
        if (sz == cap) {
            reserve(2 * cap);
        }

        alloc_traits::construct(alloc, arr + sz, std::move(value));
        ++sz;
    }
    void reserve(size_t new_cap)
    {
        if (new_cap <= cap) {
            return;
        }

        T *newarr = alloc_traits::allocate(alloc, new_cap);

        try {
            std::uninitialized_move(arr, arr + sz, newarr);
        } catch (...) {
            alloc_traits::deallocate(alloc, newarr, new_cap);
            throw;
        }

        new (newarr) T();

        alloc_traits::deallocate(alloc, arr, cap);

        arr = newarr;

        cap = new_cap;
    }
    void resize(size_t new_sz, const T &value = T())
    {
        if (new_sz > cap) {
            reserve(new_sz);
        }

        for (int i = 0; i < new_sz; ++i) {
            alloc_traits::construct(alloc, arr + i, value);
        }

        sz = new_sz;
    }
    size_t size() { return sz; }
    void swap(myVector<T> &v)
    {
        T *buffer_arr = arr;
        arr = v.arr;
        v.arr = buffer_arr;

        size_t buffer_sz = sz;
        sz = v.sz;
        v.sz = buffer_sz;

        size_t buffer_cap = cap;
        cap = v.sz;
        v.sz = buffer_cap;
    }

    T &operator[](size_t pos) { return arr[pos]; }

    const T &operator[](size_t pos) const { return arr[pos]; }

private:
    size_t sz{0};
    size_t cap{1};
    T *arr;
    Alloc alloc;
};

#endif // MYVECTOR_H
