#ifndef VECTOR_H
#define VECTOR_H

#include<VectorAllocator.h>
#include<VectorIterator.h>
#include<ConstVectorItearator.h>
#include<stdexcept>
#include<ReverseVectorIterator.h>

template <typename T>
class Vector{
private:
    T* _arr;
    size_t _size {0};
    size_t _capacity {0};
    VectorAllocator<T> _alloc;

public:

    Vector() {
        reserve(1);
    }

    explicit Vector(size_t size, const T& value = T()) {
        this->resize(size, value);
    }

    Vector(const Vector& other) : _capacity(other._capacity), _size(other._size) {
        _arr = _alloc.allocate(_capacity);

        for (size_t i = 0; i < _size; ++i) {
            _alloc.constructor(_arr+i, other._arr[i]);
        }
    }

    Vector (Vector&& other)  noexcept : _arr(other._arr), _capacity(other._capacity), _size(other._size) {
        other._arr = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    Vector& operator=(const Vector& other) {
        if (this == & other) {
            return *this;
        }

        for (size_t i = 0; i < _size; ++i) {
            _alloc.destroy(_arr + i);
        }
        _alloc.deallocate(_arr, _capacity);

        _capacity = other._capacity;
        _size = other._size;
        _arr = _alloc.allocate(_capacity);

        for (size_t i = 0; i < _size; ++i) {
            _alloc.constructor(_arr+i, other._arr[i]);
        }

        return *this;
    }


    Vector(std::initializer_list<T> list){
        reserve(list.size());
        _size = list.size();
        for (int i = 0; i < _size; i++) {
            _alloc.constructor(_arr + i, *(list.begin() + i));
        }
    }

    Vector& operator=(std::initializer_list<T> list) {
        reserve(list.size());
        _size = list.size();
        for (int i = 0; i < _size; i++) {
            _alloc.constructor(_arr + i, *(list.begin() + i));
        }
    }

    ~Vector(){
        for (size_t i = 0; i < _size; ++i) {
            _alloc.destroy(_arr + i);
        }
        _alloc.deallocate(_arr, _capacity);
    }

    size_t size() const
    {
        return _size;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    void assign(size_t size, const T& value) {
        for (size_t i = 0; i < _size; ++i) {
            _alloc.destroy(_arr + i);
        }
        _alloc.deallocate(_arr, _size);

        _capacity = size;
        _size = size;
        _arr = _alloc.allocate(_capacity);

        for (size_t i = 0; i < _size; ++i) {
            _alloc.constructor(_arr+i, value);
        }
    }


    void reserve(size_t equanity)
    {
        if(equanity <= _capacity){
            return;
        }

        T* newarr = _alloc.allocate(equanity);

        size_t i = 0;
        try {
            for (; i < _size; i++){
                _alloc.constructor(newarr+i, _arr[i]);
            }

        }  catch (...) {
            for (size_t j = 0; j < i; j++) {
                _alloc.destroy(newarr + i);
            }
            _alloc.deallocate(newarr, _size);
        }

        for(size_t i{}; i < _size; ++i){
            _alloc.destroy(_arr+i);
        }
        if (_capacity != 0) {
        _alloc.deallocate(_arr,_size);
        }
        _arr = newarr;
        _capacity = equanity;
    }

    void resize(size_t new_size, const T& value = T())
    {
        if(_capacity < new_size){
            reserve(new_size);
        }

        for (size_t i  = _size ; i < new_size; ++i){
            _arr[i] = value;
        }
        _size = new_size;
    }

    std::remove_reference_t<T>&& move(T&& arg) {
        return static_cast<std::remove_reference_t<T>&&>(arg);
    }

    template <typename ... Args>
    void emplace(size_t equanity, const Args& ... args) {
        if (_size < equanity) {
            throw std::out_of_range("Index out of bounds!");
        }

        if (_size == _capacity) {
            reserve(2 * _capacity);
        }

        for (size_t i = _size; i > equanity; --i) {
            _alloc.constructor(_arr + i, _arr[i-1]);
            _alloc.destroy(_arr + i - 1);
        }

        _alloc.constructor(_arr + equanity, T(args ...));

        _size++;
    }

    void swap(T& a, T&b)
    {
        T t = a;
        a = b;
        b = move(t);
    }

    T& at(size_t element) {
        if (element >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _arr[element];
    }

    T& front(){
        if(_size == 0){
            throw std::out_of_range("Vector is empty");
        }
        return _arr[0];
    }

    T& back(){
        if(_size == 0){
            throw std::out_of_range("Vector is empty");
        }
        return _arr[_size - 1];
    }


    T* data(){
        if(_size !=0){
        return _arr;
        }
        else {
             throw std::out_of_range("Vector is empty");
        }
    }

    template <typename ... Args>
    void emplace_back(const Args& ... args) {
        if (_capacity == _size) {
            reserve(2 * _capacity);
        }
        _alloc.constructor(_arr + _size, args ...);
        ++_size;
    }

    void push_back(const T& value) {
        emplace_back(value);
    }

    void clear(){
        for(size_t i {} ; i < _size; ++i){
            _alloc.destroy(_arr + i);
        }
        _size = 0;
    }

    void pop_back() {

        try {
            _size--;
            _alloc.destroy(_arr + _size);
        } catch (...) {
             throw std::out_of_range("Index out of range");
        }
    }

    void erase(size_t begin, size_t end) {
        if (begin > _size || end > _size || begin > end || begin < 0) {
            throw std::out_of_range("Invalid erase range");
        }

        size_t count = end - begin;

        for (size_t i = begin; i < _size - count; ++i) {
            _arr[i] = _arr[i + count];
        }

        for (size_t i = 0; i < count; ++i) {
            _alloc.destroy(_arr + _size - count + i);
        }

        _size -= count;
    }

    void swap(Vector& other) {
        T* temp_arr = _arr;
        size_t temp_size = _size;
        size_t temp_capacity = _capacity;

        _arr = other._arr;
        _size = other._size;
        _capacity = other._capacity;

        other._arr = temp_arr;
        other._size = temp_size;
        other._capacity = temp_capacity;
    }

    T& operator[](size_t index){
        return _arr[index];
    }

    const T& operator[](size_t index) const {
        return _arr[index];
    }

    bool empty(){
        return _size == 0;
    }

    void insert(size_t index, const T& value) {

        if (index > _size) {
            throw std::out_of_range("Index out of range");
        }

        if (_size == _capacity) {
            reserve(2 * _capacity);
        }

        for (size_t i = _size; i > index; --i) {
            _arr[i] = _arr[i - 1];
        }

        _alloc.constructor(_arr + index, value);
        _size++;
    }

    VectorIterator<T> begin(){
        return VectorIterator<T>(_arr);
    }

    VectorIterator<T> end(){
         return VectorIterator<T>(_arr + _size);
    }

    ConstVectorIterator<T> cbegin(){
        return ConstVectorIterator<T>(_arr);
    }

    VectorIterator<T> cend(){
        return VectorIterator<T>(_arr + _size);
    }

    ReverseVectorIterator<T> rbegin(){
        return VectorIterator<T>(_arr + _size - 1);
    }

    ReverseVectorIterator<T> rend(){
        return VectorIterator<T>(_arr - 1);
    }

};

#endif // VECTOR_H
