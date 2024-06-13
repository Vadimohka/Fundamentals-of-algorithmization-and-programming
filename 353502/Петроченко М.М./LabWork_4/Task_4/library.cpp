#ifndef LAB4VEC_LIBRARY_H
#define LAB4VEC_LIBRARY_H

#include <sys/types.h>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <new>
#include <stdexcept>
#include <utility>
#include "./iterator.cpp"

template <typename T>
class Vector {
   private:
    using Iterator = CommonIterator<false, T>;
    using ConstIterator = CommonIterator<true, T>;
    T* arr_;
    size_t cap_{};
    size_t size_{};

   public:
    Vector() {
        this->cap_ = 0;
        this->size_ = 0;
    }

    explicit Vector(size_t size, const T& value = T()) {
        this->cap_ = 0;
        this->size_ = 0;
        this->resize(size, value);
    }

    Vector(const Vector& other) {
        this->size_ = other.size_;
        this->cap_ = other.cap_;
        this->arr_ = reinterpret_cast<T*>(new int8_t[other.cap_ * sizeof(T)]);
        for (size_t i = 0; i < this->size_; ++i) {
            new (this->arr_ + i) T(other.arr_[i]);
        }
    }

    void reserve(size_t n) {
        if (this->cap_ < n) {
            T* new_arr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);
            if (this->size_ > 0) {
                for (size_t i = 0; i < this->size_; ++i) {
                    new (new_arr + i) T(this->arr_[i]);
                }
                for (size_t i = 0; i < this->size_; ++i) {
                    arr_[i].~T();
                }
            }
            this->cap_ = n;
            if (this->size_ != 0) {
                delete[] reinterpret_cast<int8_t*>(this->arr_);
            }
            this->arr_ = new_arr;
        }
    }

    void resize(size_t n, const T& value = T()) {
        if (n > cap_) {
            reserve(n);
        }
        for (size_t i = this->size_; i < n; ++i) {
            new (this->arr_ + i) T(value);
        }
        this->size_ = n;
    }

    void push_back(const T& new_item) {

        if (this->size_ == this->cap_) {
            if (this->cap_ == 0) {
                this->reserve(2);
            } else {
                this->reserve(cap_ * 2);
            }
        }
        new (this->arr_ + this->size_++) T(new_item);
    }

    T& operator[](size_t i) { return this->arr_[i]; }

    const T& operator[](size_t i) const { return this->arr_[i]; }

    T& at(size_t i) {
        if (i >= this->size_) {
            throw std::out_of_range("Index out of range");
        }
        return this->arr_[i];
    }

    const T& at(size_t i) const {
        if (i >= this->size_) {
            throw std::out_of_range("Index out of range");
        }
        return this->arr_[i];
    }

    size_t size() const { return this->size_; };

    size_t capacity() const { return this->cap_; };

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        this->size_ = other.size_;
        this->cap_ = other.cap_;
        this->arr_ = reinterpret_cast<T*>(new int8_t[other.cap_ * sizeof(T)]);
        for (size_t i = 0; i < this->size_; ++i) {
            new (this->arr_ + i) T(other.arr_[i]);
        }
        return *this;
    }

    void assign(size_t n, const T& value) {
        this->cap_ = 0;
        this->resize(n, value);
    }

    void assign(Iterator first, Iterator last) {
        this->cap_ = 0;
        this->reserve(last - first);
        size_t i = 0;
        for (auto it = first; first != last; ++first) {
            this->arr_[i] = *first;
        }
    }

    T& back() { return this->arr_[size_ - 1]; }

    const T& back() const { return this->arr_[size_ - 1]; }

    Iterator begin() { return Iterator(this->arr_); }

    ConstIterator cbegin() const { return ConstIterator(this->arr_); }

    Iterator end() { return Iterator(this->arr_ + this->size_); }

    ConstIterator cend() const {
        return ConstIterator(this->arr_ + this->size_);
    }

    void clear() { this->size_ = 0; }

    T* data() { return this->arr_; }

    template <class... Args>
    T& emplace(Iterator it, Args&&... args) {
        uint dist_from_beg = it.ptr() - this->arr_;
        if (this->size_ == this->cap_) {
            reserve(this->cap_ * 2);
        }
        new (arr_ + this->size_) T(this->arr_[this->size_ - 1]);
        this->size_ += 1;
        Iterator pos = Iterator(this->arr_ + dist_from_beg);
        for (auto iter = this->end() - 1; iter != pos; --iter) {
            *iter = *(iter - 1);
        }
        return *new ((pos).ptr()) T(std::forward<Args>(args)...);
    }

    template <class... Args>
    T& emplace_back(Args&&... args) {
        return this->emplace(this->end(), args...);
        // if (this->size_ == this->cap_) {
        //     reserve(this->cap_ * 2);
        // }
        // return *new (this->arr_ + this->size_++) T(std::forward<Args>(args)...);
    }

    bool empty() { return (this->size_ == 0); }

    void erase(Iterator iter_start, Iterator iter_end) {
        uint diff = iter_end - iter_start;
        for (auto it = iter_end; it != this->end(); ++it) {
            *(it - diff) = *it;
        }
        this->size_ -= diff;
    }

    void erase(size_t pos) {
        Iterator iter_start = Iterator(this->arr_ + pos);
        erase(iter_start, iter_start + 1);
    }

    T& front() { return this->arr_[0]; }

    void insert(size_t pos, const T& value) {
        emplace(Iterator(this->arr_ + pos), value);
    }

    size_t max_size() {
        return std::numeric_limits<ptrdiff_t>::max() / sizeof(T);
    }

    void pop_back() { this->size_--; }

    ReverseIterator<T> rbegin() {
        return ReverseIterator<T>(Iterator(this->arr_ + this->size_ - 1));
    }

    ReverseIterator<T> rend() {
        return ReverseIterator(Iterator(this->arr_ - 1));
    }

    void swap(Vector<T>& other) noexcept {
        std::swap(this->arr_, other.arr_);
        std::swap(this->size_, other.size_);
        std::swap(this->cap_, other.cap_);
    }

    ~Vector() {
        for (size_t i = 0; i < this->size_; ++i) {
            this->arr_[i].~T();
        }
        delete[] reinterpret_cast<uint8_t*>(this->arr_);
    }
};


#endif  //LAB4VEC_LIBRARY_H
