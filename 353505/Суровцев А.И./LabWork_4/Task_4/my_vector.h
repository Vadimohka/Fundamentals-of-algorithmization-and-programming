#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>
#include <initializer_list>
#include <QDebug>
#include <stdexcept>
#include <limits>
#include "my_iterator.cpp"
#include "my_reverse_iterator.cpp"

template<typename T>
class My_vector
{
    using iterator = My_iterator<T>;
    using reverse_iterator = My_reverse_iterator<T>;
    using const_iterator = My_iterator<const T>;
private:
    T *_arr = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;
public:
    //constructors
    My_vector();
    explicit My_vector(size_t n);
    My_vector(const My_vector<T>& other);
    My_vector(std::initializer_list<T> l);
    ~My_vector();
    //my_iterators
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_iterator cbegin() const;
    const_iterator cend() const;
    //operators
    T& operator[](size_t n_);
    const T& operator[](size_t n_) const;
    //functions
    void assign(const_iterator beg, const_iterator end);
    T& at(size_t pos);
    const T& at(size_t pos) const;
    T& back();
    const T& back() const;
    size_t capacity() const;
    void clear();
    T* data();
    void reserve(size_t n_size_);

    template<typename... Args>
    iterator emplace(const_iterator pos, Args&&... args);

    template<typename... Args>
    void emplace_back(Args&&... args);

    bool empty() const;
    void erase(const_iterator pos);
    void erase(const_iterator first, const_iterator last);
    T& front();
    const T& front() const;
    void insert(const_iterator pos, const T& value);
    void insert(const_iterator pos, size_t count, const T& value);
    template<typename InputIt>
    void insert(const_iterator pos, InputIt first, InputIt last);
    size_t max_size() const;
    void pop_back();
    void push_back(const T& value);
    void resize(size_t new_size, const T& value = T());
    size_t size() const;
    void swap(My_vector<T>& other);
};

#endif // MY_VECTOR_H
