#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <QMainWindow>
#include "qlogging.h"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <stdexcept>

template<typename T>
class Allocator
{
public:
    T *allocate(const std::size_t cnt)
    {
        return reinterpret_cast<T *>(::operator new(cnt * sizeof(T)));
    }

    void deallocate(void *ptr, const std::size_t) noexcept
    {
        ::operator delete(ptr);
        //qDebug() << ptr;
    }

    template<typename... Args>
    void construct(T *ptr, Args &&...args)
    {
        //qDebug() << *ptr;
        new (ptr) T(std::forward<Args>(args)...);
        //qDebug() << *ptr;
    }

    void destroy(const T *ptr) /*noexcept(noexcept(T().~T()))*/
    {
        //qDebug() << *ptr;
        ptr->~T();
    }
};

template<typename T, typename Alloc = std::allocator<T> >
class myvector
{
private:
    T *arr;
    Alloc alloc;
    std::size_t _size;
    std::size_t _capacity;

public:
    class iterator
    {
    protected:
        T *ptr;

    public:
        explicit iterator(T *pointer)
            : ptr(pointer){};

        T &operator*() { return *ptr; }

        template<typename U>
        explicit iterator(U &&iterator)
            : ptr(iterator.ptr)
        {}

        template<typename U>
        iterator &operator=(U &&other)
        {
            if (this != &other) {
                ptr = other.ptr;
            }
            return *this;
        }

        virtual ~iterator() = default;

        virtual iterator &operator+=(int d)
        {
            ptr += d;
            return *this;
        }

        virtual iterator &operator-=(int d)
        {
            ptr -= d;
            return *this;
        }

        T *operator->() { return ptr; }
        const T *operator->() const { return ptr; }

        bool operator==(const iterator &other) { return ptr == other.ptr; }
        bool operator!=(const iterator &other) { return ptr != other.ptr; }
        virtual bool operator<(const iterator &other) const { return ptr < other.ptr; }
        virtual bool operator>(const iterator &other) const { return ptr > other.ptr; }
        virtual bool operator<=(const iterator &other) const { return ptr <= other.ptr; }
        virtual bool operator>=(const iterator &other) const { return ptr >= other.ptr; }

        virtual iterator operator++() { return iterator(++ptr); }
        virtual iterator operator--() { return iterator(--ptr); }
        virtual const iterator operator++(int) { return iterator(ptr++); }
        virtual const iterator operator--(int) { return iterator(ptr--); }

        virtual iterator operator+(int d) { return iterator(ptr + d); }
        virtual iterator operator-(int d) { return iterator(ptr - d); }
        virtual int operator-(const iterator &other) { return ptr - other.ptr; }
    };

    class const_iterator : public myvector<T, Alloc>::iterator
    {
    public:
        explicit const_iterator(T *pointer)
            : myvector<T, Alloc>::iterator(pointer){};

        const T &operator*() { return *(this->ptr); }

        template<typename U>
        explicit const_iterator(U &&const_iterator)
            : iterator(const_iterator)
        {}
    };
    class reverse_iterator;

    explicit myvector(const myvector<T, Alloc> &v)
        : alloc(Alloc())
        , _size(0)
        , _capacity(0)
        , arr(nullptr)
    {
        reserve(v._capacity);
        std::size_t i = 0;
        try {
            for (; i < v._size; ++i) {
                alloc.construct(arr + i, v[i]);
            }
        } catch (...) {
            for (std::size_t j = 0; j < i; ++j) {
                alloc.destroy(arr + j);
            }
            throw;
        }
        _size = v._size;
    }

    explicit myvector(myvector<T, Alloc> &&v) noexcept
        : alloc(Alloc())
        , _size(v._size)
        , _capacity(v._capacity)
        , arr(v._array)
    {
        v._array = nullptr;
        v._capacity = 0;
        v._size = 0;
        v.reserve(1);
    }

    myvector &operator=(const myvector<T, Alloc> &v)
    {
        qDebug() << "&";
        if (&v != this) {
            clear();
            reserve(v._capacity);
            std::size_t i = 0;
            try {
                for (; i < v.size(); ++i) {
                    alloc.construct(arr + i, v[i]);
                }
            } catch (...) {
                for (std::size_t j = 0; j < i; ++j) {
                    alloc.destroy(arr + j);
                }
                throw;
            }
        }
        return *this;
    }

    myvector &operator=(myvector<T, Alloc> &&v) noexcept
    {
        for (std::size_t i = 0; i < _size; ++i) {
            alloc.destroy(arr + i);
        }
        alloc.deallocate(arr, _capacity);
        arr = nullptr;

        _size = v._size;
        _capacity = v._capacity;
        arr = v._array;
        v._array = nullptr;
        v._capacity = 0;
        v._size = 0;
        return *this;
    }

    myvector()
        : alloc(Alloc())
        , _size(0)
        , _capacity(0)
        , arr(nullptr)
    {
        reserve(1);
    }

    ~myvector()
    {
        //qDebug() << "!";
        clear();
        //resize(0);
        //qDebug() << *arr << "&";
        //qDebug() << arr << "!";
        if (arr != nullptr) {
            alloc.deallocate(arr, _capacity);
        }
        //qDebug() << 1;
    }

    myvector(std::size_t cnt, const T &value, const Alloc &alloc = std::allocator<T>())
        : alloc(alloc)
    {
        reserve(cnt);
        for (std::size_t i = 0; i < cnt; i++) {
            alloc.construct(arr + i, value);
        }
    }

    std::size_t size() { return _size; }

    std::size_t capacity() { return _capacity; }

    std::size_t max_size() { return (SIZE_MAX * 2 - 1) / sizeof(T); }

    bool empty() { return _size == 0; }

    void reserve(std::size_t n)
    {
        if (n <= _capacity) {
            return;
        }

        T *newArray = alloc.allocate(n);
        std::size_t i = 0;
        try {
            for (; i < _size; ++i) {
                alloc.construct(newArray + i, std::move_if_noexcept(arr[i]));
            }
        } catch (...) {
            for (std::size_t j = 0; j < i; ++j) {
                alloc.destroy(newArray + j);
            }
            alloc.deallocate(newArray, n);
            newArray = nullptr;
            throw;
        }
        for (i = 0; i < _size; ++i) {
            //qDebug() << i;
            alloc.destroy(arr + i);
        }
        if (arr != nullptr) {
            alloc.deallocate(arr, _capacity);
            arr = nullptr;
        }
        arr = newArray;
        //qDebug() << arr << newArray;
        _capacity = n;
    }

    void resize(std::size_t n, const T &value = T())
    {
        //qDebug() << _size << n;
        if (n > _size) {
            if (n > _capacity) {
                reserve(n);
            }
            std::size_t i = _size;
            try {
                for (; i < n; ++i) {
                    alloc.construct(arr + i, value); // lvalue
                }
            } catch (...) {
                for (std::size_t j = _size; j < i; ++j) {
                    alloc.destroy(arr + j);
                }
                throw;
            }
        }
        _size = n;
        //qDebug() << _size << n;
    }

    iterator begin() { return iterator(arr); }

    iterator end() { return iterator(arr + _size); }

    const_iterator begin() const { return const_iterator(arr); }

    const_iterator end() const { return const_iterator(arr + _size); }

    const_iterator cbegin() const { return const_iterator(arr); }

    const_iterator cend() const { return const_iterator(arr + _size); }

    reverse_iterator rbegin() { return reverse_iterator(arr + _size - 1); }

    reverse_iterator rend() { return reverse_iterator(arr - 1); }

    template<typename... Args>
    iterator emplace_back(Args &&...args)
    {
        if (_size == _capacity) {
            reserve(_capacity * 2);
        }
        //qDebug() << bool(arr == nullptr);
        alloc.construct(arr + _size, args...);
        //qDebug() << 4;
        ++_size;
        return end() - 1;
    }

    template<typename... Args>
    iterator emplace(const iterator pos, Args &&...args)
    {
        if (pos < begin() || pos > end()) {
            if (pos < begin() || pos > end()) {
                throw std::out_of_range("Wrong iterator.");
            }
        }
        if (pos == end()) {
            //qDebug() << "!";
            return emplace_back(std::forward<Args>(args)...);
        }

        T temp(args...);
        //emplace_back(temp);
        std::size_t index = pos - begin();
        //reserve(_size + 1);
        resize(_size + 1);

        for (auto i = end() - 1; i > begin() + index; --i) {
            *i = std::move(*(i - 1));
        }
        *(begin() + index) = std::move(temp);
        return begin() + index;
    }

    template<typename U>
    void push_back(U &&value)
    {
        emplace_back(std::forward<U>(value));
    }

    iterator insert(const iterator pos, T &value)
    {
        //qDebug() << value;
        return emplace(pos, value);
    }

    template<typename U>
    void assign(const std::size_t count, U &&value)
    {
        resize(0);
        resize(count, std::forward<U>(value));
    }

    void clear()
    {
        while (_size > 0) {
            //qDebug() << _size;
            pop_back();
        }
    }

    T &at(const std::size_t pos)
    {
        if (pos >= _size) {
            throw std::out_of_range("out of range");
        }
        return arr[pos];
    }

    T &operator[](const std::size_t pos) { return arr[pos]; }

    const T &operator[](const std::size_t pos) const { return arr[pos]; }

    T &back()
    {
        /*if (empty()) {
            return nullptr;
        }*/
        return arr[_size - 1];
    }

    T &front()
    {
        /*if (empty()) {
            return nullptr;
        }*/
        return *arr;
    }

    T *data() { return arr; }

    iterator erase(const iterator pos)
    {
        if (pos < begin() || pos >= end()) {
            throw std::out_of_range("Wrong iterator.");
        }

        std::size_t index = pos - begin();
        for (std::size_t i = index; i < _size - 1; ++i) {
            *(arr + i) = std::move_if_noexcept(*(arr + i + 1));
        }
        pop_back();
        //resize(_size - 1);
        return end();
    }

    iterator erase(iterator s, iterator e)
    {
        if (s > e) {
            std::swap(s, e);
        }
        if (s < begin() || e > end()) {
            throw std::out_of_range("Wrong range.");
        }

        while (e != this->end()) {
            *s = *e;
            ++s;
            ++e;
        }
        std::size_t newsize = _size - (e - s);
        qDebug() << newsize << (e - s);
        while (_size > newsize) {
            pop_back();
        }
        //resize(_size - (end - start));
        return end();
    }

    void pop_back() noexcept
    {
        if (empty()) {
            return;
        }
        alloc.destroy(arr + _size - 1);
        --_size;
    }

    void swap(myvector<T> &vect)
    {
        myvector temp = std::move(vect);
        vect = *this;
        *this = temp;
    }
};

template<typename T, typename Alloc>
class myvector<T, Alloc>::reverse_iterator : public myvector<T, Alloc>::iterator
{
public:
    explicit reverse_iterator(T *pointer)
        : myvector<T, Alloc>::iterator(pointer){};

    T &operator*() { return *(this->ptr); }

    template<typename U>
    explicit reverse_iterator(U &&reverse_iterator)
        : iterator(reverse_iterator)
    {}

    bool operator<(const iterator &other) const override { return this->ptr > other.ptr; }
    bool operator>(const iterator &other) const override { return this->ptr < other.ptr; }
    bool operator<=(const iterator &other) const override { return this->ptr >= other.ptr; }
    bool operator>=(const iterator &other) const override { return this->ptr <= other.ptr; }

    iterator operator++() override { return iterator(--this->ptr); }
    iterator operator--() override { return iterator(++this->ptr); }
    const iterator operator++(int) override { return iterator(this->ptr--); }
    const iterator operator--(int) override { return iterator(this->ptr++); }

    iterator operator+(int d) override { return iterator(this->ptr - d); }
    iterator operator-(int d) override { return iterator(this->ptr + d); }
    int operator-(const iterator &other) override { return other.ptr - this->ptr; }
};

#endif // MYVECTOR_H
