#include "my_vector.h"

template<typename T>
My_vector<T>::My_vector() : _arr(nullptr), _size(0), _capacity(0) {}

template<typename T>
My_vector<T>::My_vector(size_t n) : _size(n), _capacity(n) {
    _arr = new T[n];
    for (size_t i = 0; i < _size; ++i) {
        _arr[i] = T();
    }
}

template<typename T>
My_vector<T>::My_vector(const My_vector<T>& other) : _size(other._size), _capacity(other._capacity) {
    _arr = new T[_capacity];
    for (size_t i = 0; i < _size; ++i) {
        _arr[i] = other._arr[i];
    }
}

template<typename T>
My_vector<T>::My_vector(std::initializer_list<T> l) :
    _size(l.size()),
    _capacity(l.size()) {
    _arr = new T[_size];
    auto listIt = l.begin();
    for (size_t i = 0; i < _size; i++, listIt++) {
        _arr[i] = *listIt;
    }
}

template<typename T>
My_vector<T>::~My_vector() {
    delete[] _arr;
}

template<typename T>
typename My_vector<T>::iterator My_vector<T>::begin() {
    return iterator(_arr);
}

template<typename T>
typename My_vector<T>::iterator My_vector<T>::end() {
    return iterator(_arr + _size);
}

template<typename T>
typename My_vector<T>::const_iterator My_vector<T>::cbegin() const {
    return const_iterator(_arr);
}

template<typename T>
typename My_vector<T>::const_iterator My_vector<T>::cend() const {
    return const_iterator(_arr + _size);
}

template<typename T>
typename My_vector<T>::reverse_iterator My_vector<T>::rbegin() {
    return reverse_iterator(_arr + _size);
}

template<typename T>
typename My_vector<T>::reverse_iterator My_vector<T>::rend() {
    return reverse_iterator(_arr);
}

template<typename T>
T& My_vector<T>::operator[](size_t n_) {
    return _arr[n_];
}

template<typename T>
const T& My_vector<T>::operator[](size_t n_) const {
    return _arr[n_];
}

template<typename T>
void My_vector<T>::assign(typename My_vector<T>::const_iterator beg, typename My_vector<T>::const_iterator end) {
    delete[] _arr;
    size_t new_size = end.base() - beg.base();
    _size = new_size;
    _capacity = new_size;
    _arr = new T[_capacity];
    for (size_t i = 0; i < new_size; ++i, ++beg) {
        _arr[i] = *beg;
    }
}

template<typename T>
T& My_vector<T>::at(size_t pos) {
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _arr[pos];
}

template<typename T>
const T& My_vector<T>::at(size_t pos) const {
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return _arr[pos];
}

template<typename T>
T& My_vector<T>::back() {
    if (_size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return _arr[_size - 1];
}

template<typename T>
const T& My_vector<T>::back() const {
    if (_size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return _arr[_size - 1];
}

template<typename T>
size_t My_vector<T>::capacity() const {
    return _capacity;
}

template<typename T>
void My_vector<T>::clear() {
    delete[] _arr;
    _arr = nullptr;
    _size = 0;
    _capacity = 0;
}

template<typename T>
T* My_vector<T>::data() {
    return _arr;
}

template<typename T>
void My_vector<T>::reserve(size_t n_size_) {
    if (n_size_ <= _capacity) return;
    T *tmp_ = new T[n_size_];
    for (size_t i = 0; i < _size; i++) {
        new(tmp_ + i) T(_arr[i]);
        _arr[i].~T();
    }
    delete[] _arr;
    _arr = tmp_;
    _capacity = n_size_;
}

template<typename T>
template<typename... Args>
typename My_vector<T>::iterator My_vector<T>::emplace(const_iterator pos, Args&&... args) {
    size_t index = pos - cbegin();
    if (_size == _capacity) {
        reserve(_size == 0 ? 1 : _size * 2);
    }
    iterator iter = begin() + index;
    for (size_t i = _size; i > index; --i) {
        _arr[i] = std::move(_arr[i - 1]);
    }
    new(&_arr[index]) T(std::forward<Args>(args)...);
    ++_size;
    return iter;
}

template<typename T>
template<typename... Args>
void My_vector<T>::emplace_back(Args&&... args) {
    if (_size == _capacity) {
        reserve(_size == 0 ? 1 : _size * 2);
    }
    new(&_arr[_size]) T(std::forward<Args>(args)...);
    ++_size;
}

template<typename T>
bool My_vector<T>::empty() const {
    return _size == 0;
}

template<typename T>
void My_vector<T>::erase(const_iterator pos) {
    size_t index = pos - cbegin();
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < _size - 1; ++i) {
        _arr[i] = std::move(_arr[i + 1]);
    }
    _arr[--_size].~T();
}

template<typename T>
void My_vector<T>::erase(const_iterator first, const_iterator last) {
    size_t index_first = first - cbegin();
    size_t index_last = last - cbegin();
    if (index_first >= _size || index_last > _size || index_first >= index_last) {
        throw std::out_of_range("Invalid range");
    }
    size_t num_elements = index_last - index_first;
    for (size_t i = index_first; i < _size - num_elements; ++i) {
        _arr[i] = std::move(_arr[i + num_elements]);
    }
    for (size_t i = _size - num_elements; i < _size; ++i) {
        _arr[i].~T();
    }
    _size -= num_elements;
}

template<typename T>
T& My_vector<T>::front() {
    if (_size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return _arr[0];
}

template<typename T>
const T& My_vector<T>::front() const {
    if (_size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return _arr[0];
}

template<typename T>
void My_vector<T>::insert(const_iterator pos, const T& value) {
    emplace(pos, value);
}

template<typename T>
void My_vector<T>::insert(const_iterator pos, size_t count, const T& value) {
    for (size_t i = 0; i < count; ++i) {
        emplace(pos, value);
    }
}

template<typename T>
template<typename InputIt>
void My_vector<T>::insert(const_iterator pos, InputIt first, InputIt last) {
    for (InputIt it = first; it != last; ++it) {
        emplace(pos, *it);
        for (int i = 0; i < _arr->size(); ++i) {
            qDebug() << _arr[i] << '\t';
        }
        qDebug() << '\n';
    }
}

template<typename T>
size_t My_vector<T>::max_size() const {
    return std::numeric_limits<size_t>::max() / sizeof(T);
}

template<typename T>
void My_vector<T>::pop_back() {
    if (_size > 0) {
        _arr[--_size].~T();
    }
}

template<typename T>
void My_vector<T>::push_back(const T& value) {
    if (_size == _capacity) {
        reserve(_size == 0 ? 1 : _size * 2);
    }
    _arr[_size++] = value;
}

template<typename T>
void My_vector<T>::resize(size_t new_size, const T& value) {
    if (new_size < _size) {
        for (size_t i = new_size; i < _size; ++i) {
            _arr[i].~T();
        }
    } else if (new_size > _size) {
        if (new_size > _capacity) {
            reserve(new_size);
        }
        for (size_t i = _size; i < new_size; ++i) {
            new (&_arr[i]) T(value);
        }
    }
    _size = new_size;
}

template<typename T>
size_t My_vector<T>::size() const {
    return _size;
}

template<typename T>
void My_vector<T>::swap(My_vector<T>& other) {
    std::swap(_arr, other._arr);
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
}
