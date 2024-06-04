//
// Created by dmitry on 7.4.24.
//

#include "vector.h"

namespace mySTL {

    /* ============================================================================
     * ============================================================================
     *  Constructors for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T, typename Allocator = MyAllocator<T>>
    vector<T>::vector() noexcept {
        _arr = new T[_capacity_size];
    }

    template<typename T, typename Allocator = MyAllocator<T>>
    vector<T>::vector(typename vector<T>::uint32 n) {
        uint32 i;
        _capacity_size = n << 2;
        _arr = new T[_capacity_size];
        for (i = 0; i < n; ++i)
            _arr[i] = T();
        _size = n;
    }

    template<typename T>
    vector<T>::vector(typename vector<T>::uint32 n, const T &value) {
        uint32 i;
        _capacity_size = n << 2;
        _arr = new T[_capacity_size];
        for (i = 0; i < n; ++i)
            _arr[i] = value;
        _size = n;
    }

    template<typename T>
    template<class InputIt>
    vector<T>::vector(InputIt first, InputIt last) {
        std::cout << "Inside ... \n";
        uint32 i, count = last - first;
        std::cout << "count =" << count << std::endl;
        _capacity_size = count << 2;
        _size = count;
        _arr = new T[_capacity_size];
        for (i = 0; i < count; ++i, ++first)
            _arr[i] = *first;
    }

    template<typename T>
    vector<T>::vector(std::initializer_list<T> lst) {
        _capacity_size = lst.size() << 2;
        _arr = new T[_capacity_size];
        for (auto &item: lst)
            _arr[_size++] = item;
    }

    template<typename T>
    vector<T>::vector(const vector<T> &other) {
        uint32 i;
        _capacity_size = other._capacity_size;
        _arr = new T[_capacity_size];
        for (i = 0; i < other._size; ++i)
            _arr[i] = other._arr[i];
        _size = other._size;
    }

    template<typename T>
    vector<T>::vector(vector<T> &&other) noexcept {
        uint32 i;
        _capacity_size = other._capacity_size;
        _arr = new T[_capacity_size];
        for (i = 0; i < other._size; ++i)
            _arr[i] = std::move(other._arr[i]);
        _size = other._size;
    }

    /* ============================================================================
     * ============================================================================
     *  Destructor for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    vector<T>::~vector() {
        delete[] _arr;
    }

    /* ============================================================================
     * ============================================================================
     *  some getters function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    typename vector<T>::iterator vector<T>::begin() noexcept {
        return _arr;
    }

    template<typename T>
    typename vector<T>::const_iterator vector<T>::cbegin() const noexcept {
        return _arr;
    }

    template<typename T>
    typename vector<T>::iterator vector<T>::end() noexcept {
        return _arr + _size;
    }

    template<typename T>
    typename vector<T>::const_iterator vector<T>::cend() const noexcept {
        return _arr + _size;
    }

    template<typename T>
    typename vector<T>::reverse_iterator vector<T>::rbegin() noexcept {
        return reverse_iterator(_arr + _size);
    }

    template<typename T>
    typename vector<T>::const_reverse_iterator vector<T>::crbegin() const noexcept {
        return reverse_iterator(_arr + _size);
    }

    template<typename T>
    typename vector<T>::reverse_iterator vector<T>::rend() noexcept {
        return reverse_iterator(_arr);
    }

    template<typename T>
    typename vector<T>::const_reverse_iterator vector<T>::crend() const noexcept {
        return reverse_iterator(_arr);
    }

    template<typename T>
    bool vector<T>::empty() const noexcept {
        return _size == 0;
    }

    template<typename T>
    typename vector<T>::uint32 vector<T>::size() const noexcept {
        return _size;
    }

    template<typename T>
    typename vector<T>::uint32 vector<T>::max_size() const noexcept {
        return MYSTL_VECTOR_MAX_SZ;
    }

    template<typename T>
    typename vector<T>::uint32 vector<T>::capacity() const noexcept {
        return _capacity_size;
    }

    /* ============================================================================
     * ============================================================================
     *  assign() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    void vector<T>::assign(typename vector<T>::uint32 count, const T &value) {
        uint32 i;
        if (count > _capacity_size) {
            _capacity_size = count << 2;
            reallocate();
        }
        for (i = 0; i < count; ++i)
            _arr[i] = value;
        _size = count;
    }

    template<typename T>
    template<class InputIt>
    void vector<T>::assign(InputIt first, InputIt last) {
        uint32 i, count = last - first;
        if (count > _capacity_size) {
            _capacity_size = count << 2;
            reallocate();
        }
        for (i = 0; i < count; ++i, ++first)
            _arr[i] = *first;
        _size = count;
    }

    template<typename T>
    void vector<T>::assign(std::initializer_list<T> lst) {
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

    template<typename T>
    inline void vector<T>::reallocate() {
        T *tarr = new T[_capacity_size];
        memcpy(tarr, _arr, _size * sizeof(T));
        delete[] _arr;
        _arr = tarr;
    }

    /* ============================================================================
     * ============================================================================
     *  resize() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    void vector<T>::resize(typename vector<T>::uint32 sz) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
        } else {
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i].~T();
        }
        _size = sz;
    }

    template<typename T>
    void vector<T>::resize(typename vector<T>::uint32 sz, const T &c) {
        if (sz > _size) {
            if (sz > _capacity_size) {
                _capacity_size = sz;
                reallocate();
            }
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
        } else {
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i].~T();
        }
        _size = sz;
    }

    /* ============================================================================
     * ============================================================================
     *  reserve() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    void vector<T>::reserve(typename vector<T>::uint32 _sz) {
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

    template<typename T>
    typename vector<T>::reference vector<T>::operator[](
            typename vector<T>::uint32 idx) {
        return _arr[idx];
    }

    template<typename T>
    typename vector<T>::const_reference vector<T>::operator[](
            typename vector<T>::uint32 idx) const {
        return _arr[idx];
    }

    /* ============================================================================
     * ============================================================================
     *  at() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    typename vector<T>::reference vector<T>::at(uint32 pos) {
        if (pos < _size)
            return _arr[pos];
        else
            throw std::out_of_range("accessed position is out of range");
    }

    template<typename T>
    typename vector<T>::const_reference vector<T>::at(uint32 pos) const {
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

    template<typename T>
    typename vector<T>::reference vector<T>::front() {
        return _arr[0];
    }

    template<typename T>
    typename vector<T>::const_reference vector<T>::front() const {
        return _arr[0];
    }

    /* ============================================================================
     * ============================================================================
     *  clear() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    typename vector<T>::reference vector<T>::back() {
        return _arr[_size - 1];
    }

    template<typename T>
    typename vector<T>::const_reference vector<T>::back() const {
        return _arr[_size - 1];
    }

    /* ============================================================================
     * ============================================================================
     *  data() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    T *vector<T>::data() noexcept {
        return _arr;
    }

    template<typename T>
    const T *vector<T>::data() const noexcept {
        return _arr;
    }

    /* ============================================================================
     * ============================================================================
     *  emplace_back() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    template<class... Args>
    void vector<T>::emplace_back(Args &&... args) {
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

    template<typename T>
    void vector<T>::push_back(const T &val) {
        if (_size == _capacity_size) {
            _capacity_size <<= 2;
            reallocate();
        }
        _arr[_size] = val;
        ++_size;
    }

    template<typename T>
    void vector<T>::push_back(T &&val) {
        if (_size == _capacity_size) {
            _capacity_size <<= 2;
            reallocate();
        }

        _arr[_size] = std::move(val);
        ++_size;
    }

    /* ============================================================================
     * ============================================================================
     *  pop_back() function
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    void vector<T>::pop_back() {
        --_size;
        _arr[_size].~T();
    }

    /* ============================================================================
     * ============================================================================
     *  emplace() function for T
     * ============================================================================
     * ============================================================================
     */

    template<typename T>
    template<class... Args>
    typename vector<T>::iterator vector<T>::emplace(
            typename vector<T>::const_iterator it, Args &&... args) {
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

    template<typename T>
    typename vector<T>::iterator vector<T>::insert(typename vector<T>::const_iterator it, const T &val) {
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

    template<typename T>
    typename vector<T>::iterator vector<T>::insert(typename vector<T>::const_iterator it, T &&val) {
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

    template<typename T>
    typename vector<T>::iterator vector<T>::insert(typename vector<T>::const_iterator it,
                                                   typename vector<T>::uint32 cnt,
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

    template<typename T>
    template<class InputIt>
    typename vector<T>::iterator vector<T>::insert(typename vector<T>::const_iterator it,
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

    template<typename T>
    typename vector<T>::iterator vector<T>::insert(typename vector<T>::const_iterator it,
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

    template<typename T>
    typename vector<T>::iterator vector<T>::erase(
            typename vector<T>::const_iterator it) {
        iterator iit = &_arr[it - _arr];
        (*iit).~T();
        memmove(iit, iit + 1, (_size - (it - _arr) - 1) * sizeof(T));
        --_size;
        return iit;
    }

    template<typename T>
    typename vector<T>::iterator vector<T>::erase(
            typename vector<T>::const_iterator first,
            typename vector<T>::const_iterator last) {
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

    template<typename T>
    void vector<T>::swap(vector<T> &rhs) {
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

    template<typename T>
    void vector<T>::clear() noexcept {
        uint32 i;
        for (i = 0; i < _size; ++i)
            _arr[i].~T();
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
            uint32 i;
            for (i = _size; i < sz; ++i)
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
            uint32 i;
            for (i = _size; i < sz; ++i)
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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
            uint32 i;
            for (i = _size; i < sz; ++i)
                _arr[i] = c;
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

    template<typename T>
    vector<T> &vector<T>::operator=(const vector<T> &other) {

        if (this == &other) {
            return *this;
        }
        uint32 i;
        if (_capacity_size < other._size) {
            _capacity_size = other._size << 2;
            reallocate();
        }
        for (i = 0; i < other._size; ++i)
            _arr[i] = other._arr[i];
        _size = other._size;
    }

    template<typename T>
    vector<T> &vector<T>::operator=(vector<T> &&other) {
        uint32 i;
        if (_capacity_size < other._size) {
            _capacity_size = other._size << 2;
            reallocate();
        }
        for (i = 0; i < other._size; ++i)
            _arr[i] = std::move(other._arr[i]);
        _size = other._size;
    }

    template<typename T>
    vector<T> &vector<T>::operator=(std::initializer_list<T> lst) {
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

    template<typename T>
    bool vector<T>::operator==(const vector<T> &rhs) const {
        if (_size != rhs._size)
            return false;
        uint32 i;
        for (i = 0; i < _size; ++i)
            if (_arr[i] != rhs._arr[i])
                return false;
        return true;
    }

    template<typename T>
    bool vector<T>::operator!=(const vector<T> &rhs) const {
        if (_size != rhs._size)
            return true;
        uint32 i;
        for (i = 0; i < _size; ++i)
            if (_arr[i] != rhs._arr[i])
                return true;
        return false;
    }

    template<typename T>
    bool vector<T>::operator<(const vector<T> &rhs) const {
        uint32 i, j, ub = _size < rhs._size ? _size : rhs._size;
        for (i = 0; i < ub; ++i)
            if (_arr[i] != rhs._arr[i])
                return _arr[i] < rhs._arr[i];
        return _size < rhs._size;
    }

    template<typename T>
    bool vector<T>::operator<=(const vector<T> &rhs) const {
        uint32 i, j, ub = _size < rhs._size ? _size : rhs._size;
        for (i = 0; i < ub; ++i)
            if (_arr[i] != rhs._arr[i])
                return _arr[i] < rhs._arr[i];
        return _size <= rhs._size;
    }

    template<typename T>
    bool vector<T>::operator>(const vector<T> &rhs) const {
        uint32 i, j, ub = _size < rhs._size ? _size : rhs._size;
        for (i = 0; i < ub; ++i)
            if (_arr[i] != rhs._arr[i])
                return _arr[i] > rhs._arr[i];
        return _size > rhs._size;
    }

    template<typename T>
    bool vector<T>::operator>=(const vector<T> &rhs) const {
        uint32 i, j, ub = _size < rhs._size ? _size : rhs._size;
        for (i = 0; i < ub; ++i)
            if (_arr[i] != rhs._arr[i])
                return _arr[i] > rhs._arr[i];
        return _size >= rhs._size;
    }

}//namespace mySTL