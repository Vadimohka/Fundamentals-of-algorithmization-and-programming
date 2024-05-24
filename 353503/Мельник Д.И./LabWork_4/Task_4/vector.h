//
// Created by dmitry on 6.4.24.
//

#include <cstddef>
#include <cstring>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <utility>

#include "allocator.h"

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#define MYSTL_VECTOR_MAX_SZ 1000000000

namespace mySTL {

    template<typename T, typename Allocator = MyAllocator<T>>
    class vector {
    public:
//types:
        using reference = T&;              // Type alias for reference to T
        using const_reference = const T&;  // Type alias for const reference to T
        using iterator = T*;               // Type alias for iterator to T
        using const_iterator = const T*;   // Type alias for const iterator to T
        using reverse_iterator = std::reverse_iterator<iterator>;              // Type alias for reverse iterator to T
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;  // Type alias for const reverse iterator to T
        using uint32 = unsigned long int;                                      // Type alias for size type

// construct/copy/destroy:
        vector() noexcept;               // Default constructor
        explicit vector(uint32 n);       // Constructor that initializes the vector with n elements
        vector(uint32 n, const T &val);  // Constructor that initializes the vector with n elements,
        // all of them are copies of val

        template<class InputIt>
        vector(InputIt first, InputIt last); // Constructor that initializes the vector
        // with elements from range (first, last)

        vector(std::initializer_list<T>); // Constructor that initializes the vector with initializer list
        vector(const vector<T> &);        // Copy constructor
        vector(vector<T> &&) noexcept;    // Move constructor
        ~vector();  // Destructor

        vector<T> &operator=(const vector<T> &);        // Copy assignment operator
        vector<T> &operator=(vector<T> &&);             // Move assignment operator
        vector<T> &operator=(std::initializer_list<T>); // Assignment operator from initializer list

        void assign(uint32, const T &value);   // Assigns new contents to the vector,
        // replacing its current contents, and modifying its size accordingly.

        template<class InputIt>
        void assign(InputIt, InputIt);         // Assigns new contents to the vector,
        // replacing its current contents, and modifying its size accordingly.

        void assign(std::initializer_list<T>); // Assigns new contents to the vector,
        // replacing its current contents, and modifying its size accordingly.

// iterators:
        iterator begin() noexcept;              // Returns an iterator pointing to the first element
        const_iterator cbegin() const noexcept; // Returns a const iterator pointing to the first element
        iterator end() noexcept;                // Returns an iterator pointing to the past-the-end element

        const_iterator cend() const noexcept; // Returns a const iterator pointing
        // to the past-the-end element in the vector

        reverse_iterator rbegin() noexcept; // Returns a reverse iterator pointing
        // to the last element in the vector (reverse beginning)

        const_reverse_iterator crbegin() const noexcept; // Returns a const reverse iterator pointing
        // to the last element in the vector (reverse beginning)

        reverse_iterator rend() noexcept; // Returns a reverse iterator pointing
        // to the theoretical element preceding the first element in the vector (reverse end)

        const_reverse_iterator crend() const noexcept; // Returns a const reverse iterator pointing
        // to the theoretical element preceding the first element in the vector (reverse end)

// capacity:
        bool empty() const noexcept;      // Checks if the container has no elements
        uint32 size() const noexcept;     // Returns the number of elements in the container
        uint32 max_size() const noexcept; // Returns the maximum possible number of elements in the container
        uint32 capacity() const noexcept; // Returns the number of elements that can be held
        // in currently allocated storage

        void resize(uint32);            // Changes the number of elements stored
        void resize(uint32, const T &); // Changes the number of elements stored,
        // new elements are initialized with val

        void reserve(uint32); // Requests that the vector capacity be at least enough to contain n elements

// element access
        reference operator[](uint32);             // Access element
        const_reference operator[](uint32) const; // Access element
        reference at(uint32);             // Access element with bounds checking
        const_reference at(uint32) const; // Access element with bounds checking
        reference front();             // Access the first element
        const_reference front() const; // Access the first element
        reference back();              // Access the last element
        const_reference back() const;  // Access the last element

// data access:
        T *data() noexcept;             // Direct access to the underlying array
        const T *data() const noexcept; // Direct access to the underlying array

// modifiers:
        template<class... Args>
        void emplace_back(Args &&... args); // Constructs an element in-place at the end
        void push_back(const T &);          // Adds an element to the end
        void push_back(T &&);               // Moves an element to the end
        void pop_back();                    // Removes the last element
        void swap(vector<T> &); // Swaps the contents
        void clear() noexcept;  // Clears the contents

        template<class... Args>
        iterator emplace(const_iterator, Args &&...);       // Constructs an element in-place in the container
        iterator insert(const_iterator, const T &);         // Inserts elements at a certain position
        iterator insert(const_iterator, T &&);              // Moves elements into the container
        iterator insert(const_iterator, uint32, const T &); // Inserts elements at a certain position
        template<class InputIt>
        iterator insert(const_iterator, InputIt, InputIt);         // Inserts elements from range (first, last)
        iterator insert(const_iterator, std::initializer_list<T>); // Inserts elements from initializer list
        iterator erase(const_iterator);                 // Erases elements at a certain position
        iterator erase(const_iterator, const_iterator); // Erases elements in a range

// Comparisons:
        bool operator==(const vector<T> &) const; // Compares for equality
        bool operator!=(const vector<T> &) const; // Compares for inequality
        bool operator< (const vector<T> &) const; // Compares for less than
        bool operator<=(const vector<T> &) const; // Compares for less than or equal to
        bool operator> (const vector<T> &) const; // Compares for greater than
        bool operator>=(const vector<T> &) const; // Compares for greater than or equal to

    private:
        Allocator _allocator;
        uint32 _capacity_size = 4;
        uint32 _size = 0;
        T *_arr;

        inline void reallocate();
    };



    /* ============================================================================
     * ============================================================================
     *  Constructors for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    vector<T, Allocator>::vector() noexcept {
        _arr = _allocator.allocate(_capacity_size);
    }

    template<typename T, typename Allocator>
    vector<T, Allocator>::vector(typename vector<T, Allocator>::uint32 n) {
        _capacity_size = n << 2;
        _arr = _allocator.allocate(_capacity_size);
        for (uint32 i = 0; i < n; ++i) { _allocator.construct(_arr + i, _arr[i]); }
        _size = n;
    }

    template<typename T, typename Allocator>
    vector<T, Allocator>::vector(typename vector<T, Allocator>::uint32 n, const T &value) {
        uint32 i;
        _capacity_size = n << 2;
        _arr = _allocator.allocate(_capacity_size);
        for (i = 0; i < n; ++i) { _allocator.construct(_arr + i, value); }
        _size = n;
    }

    template<typename T, typename Allocator>
    template<class InputIt>
    vector<T, Allocator>::vector(InputIt first, InputIt last) {
        std::cout << "Inside ... \n";
        uint32 i, count = last - first;
        std::cout << "count =" << count << std::endl;
        _capacity_size = count << 2;
        _size = count;
        _arr = _allocator.allocate(_capacity_size);
        for (i = 0; i < count; ++i, ++first) { _allocator.construct(_arr + i, *first); }
    }

    template<typename T, typename Allocator>
    vector<T, Allocator>::vector(std::initializer_list<T> lst) {
        _capacity_size = lst.size() << 2;
        _arr = _allocator.allocator(_capacity_size);
        for (auto &item: lst) {
            _arr[_size++] = item;
        }
    }

    template<typename T, typename Allocator>
    vector<T, Allocator>::vector(const vector<T> &other) {
        _capacity_size = other._capacity_size;
        _arr = _allocator.allocate(_capacity_size);
        for (uint32 i = 0; i < other._size; ++i) { _allocator.construct(_arr + i, other._arr[i]); }
        _size = other._size;
    }

    template<typename T, typename Allocator>
    vector<T, Allocator>::vector(vector<T> &&other) noexcept {
        uint32 i;
        _capacity_size = other._capacity_size;
        _arr = _allocator(_capacity_size);
        for (i = 0; i < other._size; ++i) { _allocator.construct(_arr + i, std::move(other._arr[i])); }
        _size = other._size;
    }

    /* ============================================================================
     * ============================================================================
     *  Destructor for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    vector<T, Allocator>::~vector() {
        _allocator.destroy(_arr);
        _allocator.deallocate(_arr, _size);
    }

    /* ============================================================================
     * ============================================================================
     *  some getters function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() noexcept {
        return _arr;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::cbegin() const noexcept {
        return _arr;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::end() noexcept {
        return _arr + _size;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::cend() const noexcept {
        return _arr + _size;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin() noexcept {
        return reverse_iterator(_arr + _size);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::crbegin() const noexcept {
        return reverse_iterator(_arr + _size);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend() noexcept {
        return reverse_iterator(_arr);
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::crend() const noexcept {
        return reverse_iterator(_arr);
    }

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::empty() const noexcept {
        return _size == 0;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::uint32 vector<T, Allocator>::size() const noexcept {
        return _size;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::uint32 vector<T, Allocator>::max_size() const noexcept {
        return MYSTL_VECTOR_MAX_SZ;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::uint32 vector<T, Allocator>::capacity() const noexcept {
        return _capacity_size;
    }

    /* ============================================================================
     * ============================================================================
     *  assign() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    void vector<T, Allocator>::assign(typename vector<T, Allocator>::uint32 count, const T &value) {
        uint32 i;
        if (count > _capacity_size) {
            _capacity_size = count << 2;
            reallocate();
        }
        for (i = 0; i < count; ++i){ _allocator.construct(_arr + i, value); }
        _size = count;
    }

    template<typename T, typename Allocator>
    template<class InputIt>
    void vector<T, Allocator>::assign(InputIt first, InputIt last) {
        uint32 i, count = last - first;
        if (count > _capacity_size) {
            _capacity_size = count << 2;
            reallocate();
        }
        for (i = 0; i < count; ++i, ++first) { _allocator.construct(_arr + i, *first); }
        _size = count;
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::assign(std::initializer_list<T> lst) {
        uint32 i, count = lst.size();
        if (count > _capacity_size) {
            _capacity_size = count << 2;
            reallocate();
        }
        i = 0;
        for (auto &item: lst)
            _arr[i++] = item;
    }

    /* ============================================================================
     * ============================================================================
     *  reallocate() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    inline void vector<T, Allocator>::reallocate() {
        T *tarr = _allocator.allocate(_capacity_size);
        for (uint32 i = 0; i < _size; ++i) { _allocator.construct(tarr + i, _arr[i]); }
        for (uint32 i = 0; i < _size; ++i) { _allocator.destroy(&_arr[i]); }
        _allocator.deallocate(_arr, _size);
        _arr = tarr;
    }

    /* ============================================================================
     * ============================================================================
     *  resize() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    void vector<T, Allocator>::resize(typename vector<T, Allocator>::uint32 sz) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
        }
        else {
            for (uint32 i = _size; i < sz; ++i) { _allocator.destroy(_arr[i]); }
        }
        _size = sz;
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::resize(typename vector<T, Allocator>::uint32 sz, const T &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _arr[i] = c; }
        }
        else {
            for (uint32 i = _size; i < sz; ++i) { _allocator.destroy(_arr[i]); }
        }
        _size = sz;
    }

    /* ============================================================================
     * ============================================================================
     *  reserve() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    void vector<T, Allocator>::reserve(typename vector<T, Allocator>::uint32 _sz) {
        if (_sz > _capacity_size) {
            _capacity_size = _sz;
            reallocate();
        }
    }

    /* ============================================================================
     * ============================================================================
     *  operator[] for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::operator[](
            typename vector<T, Allocator>::uint32 idx) {
        return _arr[idx];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[](
            typename vector<T, Allocator>::uint32 idx) const {
        return _arr[idx];
    }

    /* ============================================================================
     * ============================================================================
     *  at() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::at(uint32 pos) {
        if (pos < _size)
            return _arr[pos];
        else
            throw std::out_of_range("accessed position is out of range");
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(uint32 pos) const {
        if (pos < _size)
            return _arr[pos];
        else
            throw std::out_of_range("accessed position is out of range");
    }

    /* ============================================================================
     * ============================================================================
     *  front() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::front() {
        return _arr[0];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const {
        return _arr[0];
    }

    /* ============================================================================
     * ============================================================================
     *  clear() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::reference vector<T, Allocator>::back() {
        return _arr[_size - 1];
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const {
        return _arr[_size - 1];
    }

    /* ============================================================================
     * ============================================================================
     *  data() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    T *vector<T, Allocator>::data() noexcept {
        return _arr;
    }

    template<typename T, typename Allocator>
    const T *vector<T, Allocator>::data() const noexcept {
        return _arr;
    }

    /* ============================================================================
     * ============================================================================
     *  emplace_back() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    template<class... Args>
    void vector<T, Allocator>::emplace_back(Args &&... args) {
        if (_size == _capacity_size) {
            _capacity_size <<= 2;
            reallocate();
        }
        _arr[_size] = std::move(T(std::forward<Args>(args)...));
        ++_size;
    }

    /* ============================================================================
     * ============================================================================
     *  push_back() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    void vector<T, Allocator>::push_back(const T &val) {
        if (_size == _capacity_size) {
            _capacity_size <<= 2;
            reallocate();
        }
        _allocator.construct(&_arr[_size], val);
        ++_size;
    }

    template<typename T, typename Allocator>
    void vector<T, Allocator>::push_back(T &&val) {
        if (_size == _capacity_size) {
            _capacity_size <<= 2;
            reallocate();
        }
        _allocator.construct(&_arr[_size], std::move(val));
        ++_size;
        std::cout << "push value: " << val << std::endl;
    }

    /* ============================================================================
     * ============================================================================
     *  pop_back() function
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    void vector<T, Allocator>::pop_back() {
        --_size;
        _allocator.destroy(_arr[_size]);
    }

    /* ============================================================================
     * ============================================================================
     *  emplace() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    template<class... Args>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::emplace(
            typename vector<T, Allocator>::const_iterator it, Args &&... args) {
        iterator iit = &_arr[it - _arr];
        if (_size == _capacity_size) {
            _capacity_size <<= 2;
            reallocate();
        }
        memmove(iit + 1, iit, (_size - (it - _arr)) * sizeof(T));
        (*iit) = std::move(T(std::forward<Args>(args)...));
        ++_size;
        return iit;
    }

    /* ============================================================================
     * ============================================================================
     *  insert() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(typename vector<T, Allocator>::const_iterator it, const T &val) {
        iterator iit = &_arr[it - _arr];
        if (_size == _capacity_size) {
            _capacity_size <<= 2;
            reallocate();
        }
        memmove(iit + 1, iit, (_size - (it - _arr)) * sizeof(T));
        (*iit) = val;
        ++_size;
        return iit;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(typename vector<T, Allocator>::const_iterator it, T &&val) {
        iterator iit = &_arr[it - _arr];
        if (_size == _capacity_size) {
            _capacity_size <<= 2;
            reallocate();
        }
        memmove(iit + 1, iit, (_size - (it - _arr)) * sizeof(T));
        (*iit) = std::move(val);
        ++_size;
        return iit;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(typename vector<T, Allocator>::const_iterator it,
                                                   typename vector<T, Allocator>::uint32 cnt,
                                                   const T &val) {
        iterator f = &_arr[it - _arr];
        if (!cnt)
            return f;
        if (_size + cnt > _capacity_size) {
            _capacity_size = (_size + cnt) << 2;
            reallocate();
        }
        memmove(f + cnt, f, (_size - (it - _arr)) * sizeof(T));
        _size += cnt;
        for (iterator it = f; cnt--; ++it)
            (*it) = val;
        return f;
    }

    template<typename T, typename Allocator>
    template<class InputIt>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(typename vector<T, Allocator>::const_iterator it,
                                                   InputIt first, InputIt last) {
        iterator f = &_arr[it - _arr];
        uint32 cnt = last - first;
        if (!cnt)
            return f;
        if (_size + cnt > _capacity_size) {
            _capacity_size = (_size + cnt) << 2;
            reallocate();
        }
        memmove(f + cnt, f, (_size - (it - _arr)) * sizeof(T));
        for (iterator it = f; first != last; ++it, ++first)
            (*it) = *first;
        _size += cnt;
        return f;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(typename vector<T, Allocator>::const_iterator it,
                                                   std::initializer_list<T> lst) {
        uint32 cnt = lst.size();
        iterator f = &_arr[it - _arr];
        if (!cnt)
            return f;
        if (_size + cnt > _capacity_size) {
            _capacity_size = (_size + cnt) << 2;
            reallocate();
        }
        memmove(f + cnt, f, (_size - (it - _arr)) * sizeof(T));
        iterator iit = f;
        for (auto &item: lst) {
            (*iit) = item;
            ++iit;
        }
        _size += cnt;
        return f;
    }

    /* ============================================================================
     * ============================================================================
     *  erase() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(
            typename vector<T, Allocator>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        (*iit).~T();
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(T));
        --_size;
        return iit;
    }

    template<typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(
            typename vector<T, Allocator>::const_iterator first,
            typename vector<T, Allocator>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        for (; first != last; ++first)
            (*first).~T();
        memmove(f, last, (_size - (last - _arr)) * sizeof(T));
        _size -= last - first;
        return f;
    }

    /* ============================================================================
     * ============================================================================
     *  swap() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    void vector<T, Allocator>::swap(vector<T> &rhs) {
        size_t tvec_sz = _size, trsrv_sz = _capacity_size;
        T *tarr = _arr;

        _size = rhs._size;
        _capacity_size = rhs._capacity_size;
        _arr = rhs._arr;

        rhs._size = tvec_sz;
        rhs._capacity_size = trsrv_sz;
        rhs._arr = tarr;
    }

    /* ============================================================================
     * ============================================================================
     *  clear() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    void vector<T, Allocator>::clear() noexcept {
        for (uint32 i = 0; i < _size; ++i) { _allocator.destroy(_arr[i]); }
        _size = 0;
    }

    /* ============================================================================
     * ============================================================================
     * resize() function for all types
     * ============================================================================
     * ============================================================================
     */

    template<>
    void vector<bool>::resize(typename vector<bool>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<signed char>::resize(typename vector<signed char>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<unsigned char>::resize(typename vector<unsigned char>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<char>::resize(typename vector<char>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<short int>::resize(typename vector<short int>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<unsigned short int>::resize(
            typename vector<unsigned short int>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<int>::resize(typename vector<int>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<unsigned int>::resize(typename vector<unsigned int>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<long int>::resize(typename vector<long int>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<unsigned long int>::resize(typename vector<unsigned long int>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<long long int>::resize(typename vector<long long int>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<unsigned long long int>::resize(typename vector<unsigned long long int>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<float>::resize(typename vector<float>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<double>::resize(typename vector<double>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<long double>::resize(typename vector<long double>::uint32 sz) {
        if (sz > _capacity_size) {
            _capacity_size = sz;
            reallocate();
        }
        _size = sz;
    }

    template<>
    void vector<bool>::resize(typename vector<bool>::uint32 sz, const bool &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i)
                _arr[i] = c;
        }
        _size = sz;
    }

    template<>
    void vector<signed char>::resize(typename vector<signed char>::uint32 sz,
                                     const signed char &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i)
                _arr[i] = c;
        }
        _size = sz;
    }

    template<>
    void vector<unsigned char>::resize(typename vector<unsigned char>::uint32 sz,
                                       const unsigned char &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<char>::resize(typename vector<char>::uint32 sz, const char &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<short int>::resize(typename vector<short int>::uint32 sz,
                                   const short int &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<unsigned short int>::resize(typename vector<unsigned short int>::uint32 sz,
                                            const unsigned short int &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<int>::resize(typename vector<int>::uint32 sz, const int &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<unsigned int>::resize(typename vector<unsigned int>::uint32 sz,
                                      const unsigned int &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<long int>::resize(typename vector<long int>::uint32 sz,
                                  const long int &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<unsigned long int>::resize(typename vector<unsigned long int>::uint32 sz,
                                           const unsigned long int &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<long long int>::resize(typename vector<long long int>::uint32 sz,
                                       const long long int &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<unsigned long long int>::resize(typename vector<unsigned long long int>::uint32 sz,
                                                const unsigned long long int &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<float>::resize(typename vector<float>::uint32 sz,
                               const float &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<double>::resize(typename vector<double>::uint32 sz,
                                const double &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr +i, c); }
        }
        _size = sz;
    }

    template<>
    void vector<long double>::resize(typename vector<long double>::uint32 sz,
                                     const long double &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            for (uint32 i = _size; i < sz; ++i) { _allocator.construct(_arr + i, c); }
        }
        _size = sz;
    }

    /* ============================================================================
     * ============================================================================
     * pop_back() function for all base types
     * ============================================================================
     * ============================================================================
     */

    template<>
    void vector<bool>::pop_back() {
        --_size;
    }

    template<>
    void vector<signed char>::pop_back() {
        --_size;
    }

    template<>
    void vector<unsigned char>::pop_back() {
        --_size;
    }

    template<>
    void vector<char>::pop_back() {
        --_size;
    }

    template<>
    void vector<short int>::pop_back() {
        --_size;
    }

    template<>
    void vector<unsigned short int>::pop_back() {
        --_size;
    }

    template<>
    void vector<int>::pop_back() {
        --_size;
    }

    template<>
    void vector<unsigned int>::pop_back() {
        --_size;
    }

    template<>
    void vector<long int>::pop_back() {
        --_size;
    }

    template<>
    void vector<unsigned long int>::pop_back() {
        --_size;
    }

    template<>
    void vector<long long int>::pop_back() {
        --_size;
    }

    template<>
    void vector<unsigned long long int>::pop_back() {
        --_size;
    }

    template<>
    void vector<float>::pop_back() {
        --_size;
    }

    template<>
    void vector<double>::pop_back() {
        --_size;
    }

    template<>
    void vector<long double>::pop_back() {
        --_size;
    }

    /* ============================================================================
     * ============================================================================
     * erase() function for all base types
     * ============================================================================
     * ============================================================================
     */

    template<>
    typename vector<bool>::iterator vector<bool>::erase(
            typename vector<bool>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(bool));
        --_size;
        return iit;
    }

    template<>
    typename vector<signed char>::iterator vector<signed char>::erase(
            typename vector<signed char>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(signed char));
        --_size;
        return iit;
    }

    template<>
    typename vector<unsigned char>::iterator vector<unsigned char>::erase(
            typename vector<unsigned char>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(unsigned char));
        --_size;
        return iit;
    }

    template<>
    typename vector<char>::iterator vector<char>::erase(
            typename vector<char>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(char));
        --_size;
        return iit;
    }

    template<>
    typename vector<short int>::iterator vector<short int>::erase(
            typename vector<short int>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(short int));
        --_size;
        return iit;
    }

    template<>
    typename vector<unsigned short int>::iterator vector<unsigned short int>::erase(
            typename vector<unsigned short int>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(unsigned short int));
        --_size;
        return iit;
    }

    template<>
    typename vector<int>::iterator vector<int>::erase(
            typename vector<int>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(int));
        --_size;
        return iit;
    }

    template<>
    typename vector<unsigned int>::iterator vector<unsigned int>::erase(
            typename vector<unsigned int>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(unsigned int));
        --_size;
        return iit;
    }

    template<>
    typename vector<long int>::iterator vector<long int>::erase(
            typename vector<long int>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(long int));
        --_size;
        return iit;
    }

    template<>
    typename vector<unsigned long int>::iterator vector<unsigned long int>::erase(
            typename vector<unsigned long int>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(unsigned long int));
        --_size;
        return iit;
    }

    template<>
    typename vector<long long int>::iterator vector<long long int>::erase(
            typename vector<long long int>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(long long int));
        --_size;
        return iit;
    }

    template<>
    typename vector<unsigned long long int>::iterator vector<unsigned long long int>::erase(
            typename vector<unsigned long long int>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1,
                (_size - (it - _arr) - 1) * sizeof(unsigned long long int));
        --_size;
        return iit;
    }

    template<>
    typename vector<float>::iterator vector<float>::erase(
            typename vector<float>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(float));
        --_size;
        return iit;
    }

    template<>
    typename vector<double>::iterator vector<double>::erase(
            typename vector<double>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(double));
        --_size;
        return iit;
    }

    template<>
    typename vector<long double>::iterator vector<long double>::erase(
            typename vector<long double>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(long double));
        --_size;
        return iit;
    }

    template<>
    typename vector<bool>::iterator vector<bool>::erase(
            typename vector<bool>::const_iterator first,
            typename vector<bool>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(bool));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<signed char>::iterator vector<signed char>::erase(
            typename vector<signed char>::const_iterator first,
            typename vector<signed char>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(signed char));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<unsigned char>::iterator vector<unsigned char>::erase(
            typename vector<unsigned char>::const_iterator first,
            typename vector<unsigned char>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(unsigned char));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<char>::iterator vector<char>::erase(
            typename vector<char>::const_iterator first,
            typename vector<char>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(char));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<short int>::iterator vector<short int>::erase(
            typename vector<short int>::const_iterator first,
            typename vector<short int>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(short int));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<unsigned short int>::iterator vector<unsigned short int>::erase(
            typename vector<unsigned short int>::const_iterator first,
            typename vector<unsigned short int>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(unsigned short int));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<int>::iterator vector<int>::erase(
            typename vector<int>::const_iterator first,
            typename vector<int>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(int));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<unsigned int>::iterator vector<unsigned int>::erase(
            typename vector<unsigned int>::const_iterator first,
            typename vector<unsigned int>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(unsigned int));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<long long int>::iterator vector<long long int>::erase(
            typename vector<long long int>::const_iterator first,
            typename vector<long long int>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(long long int));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<unsigned long long int>::iterator vector<unsigned long long int>::erase(
            typename vector<unsigned long long int>::const_iterator first,
            typename vector<unsigned long long int>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(unsigned long long int));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<float>::iterator vector<float>::erase(
            typename vector<float>::const_iterator first,
            typename vector<float>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(float));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<double>::iterator vector<double>::erase(
            typename vector<double>::const_iterator first,
            typename vector<double>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(double));
        _size -= last - first;
        return f;
    }

    template<>
    typename vector<long double>::iterator vector<long double>::erase(
            typename vector<long double>::const_iterator first,
            typename vector<long double>::const_iterator last) {
        iterator f = &_arr[first - _arr];
        if (first == last)
            return f;
        memmove(f, last, (_size - (last - _arr)) * sizeof(long double));
        _size -= last - first;
        return f;
    }

    /* ============================================================================
     * ============================================================================
     * clear() function for all base types
     * ============================================================================
     * ============================================================================
     */

    template<>
    void vector<bool>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<signed char>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<unsigned char>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<char>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<short int>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<unsigned short int>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<int>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<unsigned int>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<long int>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<unsigned long int>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<long long int>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<unsigned long long int>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<float>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<double>::clear() noexcept {
        _size = 0;
    }

    template<>
    void vector<long double>::clear() noexcept {
        _size = 0;
    }

    /* ============================================================================
     * ============================================================================
     * Operator overloads for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    vector<T> &vector<T, Allocator>::operator=(const vector<T> &other) {

        if (this == &other) {
            return *this;
        }
        if (_capacity_size < other._size) {
            _capacity_size = other._size << 2;
            reallocate();
        }
        for (uint32 i = 0; i < other._size; ++i) { _allocator.construct(_arr + i, other._arr[i]); }
        _size = other._size;
    }

    template<typename T, typename Allocator>
    vector<T> &vector<T, Allocator>::operator=(vector<T> &&other) {
        if (_capacity_size < other._size) {
            _capacity_size = other._size << 2;
            reallocate();
        }
        for (uint32 i = 0; i < other._size; ++i) { _allocator.construct(_arr + i, std::move(other._arr[i])); }
        _size = other._size;
    }

    template<typename T, typename Allocator>
    vector<T> &vector<T, Allocator>::operator=(std::initializer_list<T> lst) {
        if (_capacity_size < lst.size()) {
            _capacity_size = lst.size() << 2;
            reallocate();
        }
        _size = 0;
        for (auto &item: lst)
            _arr[_size++] = item;
    }

    /* ============================================================================
     * ============================================================================
     * comparison operators for all types
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator==(const vector<T> &rhs) const {
        if (_size != rhs._size)
            return false;
        uint32 i;
        for (i = 0; i < _size; ++i)
            if (_arr[i] != rhs._arr[i])
                return false;
        return true;
    }

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator!=(const vector<T> &rhs) const {
        if (_size != rhs._size)
            return true;
        uint32 i;
        for (i = 0; i < _size; ++i)
            if (_arr[i] != rhs._arr[i])
                return true;
        return false;
    }

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator<(const vector<T> &rhs) const {
        uint32 i, j, ub = _size < rhs._size ? _size : rhs._size;
        for (i = 0; i < ub; ++i)
            if (_arr[i] != rhs._arr[i])
                return _arr[i] < rhs._arr[i];
        return _size < rhs._size;
    }

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator<=(const vector<T> &rhs) const {
        uint32 i, j, ub = _size < rhs._size ? _size : rhs._size;
        for (i = 0; i < ub; ++i)
            if (_arr[i] != rhs._arr[i])
                return _arr[i] < rhs._arr[i];
        return _size <= rhs._size;
    }

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator>(const vector<T> &rhs) const {
        uint32 i, j, ub = _size < rhs._size ? _size : rhs._size;
        for (i = 0; i < ub; ++i)
            if (_arr[i] != rhs._arr[i])
                return _arr[i] > rhs._arr[i];
        return _size > rhs._size;
    }

    template<typename T, typename Allocator>
    bool vector<T, Allocator>::operator>=(const vector<T> &rhs) const {
        uint32 i, j, ub = _size < rhs._size ? _size : rhs._size;
        for (i = 0; i < ub; ++i)
            if (_arr[i] != rhs._arr[i])
                return _arr[i] > rhs._arr[i];
        return _size >= rhs._size;
    }

} // namespace mySTL

#endif