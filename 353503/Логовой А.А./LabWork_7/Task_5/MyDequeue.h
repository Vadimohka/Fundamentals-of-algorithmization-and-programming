#ifndef MYDEQUEUE_H
#define MYDEQUEUE_H

#include <stdexcept>
#include<QDebug>

template<typename T>
class Iterator;

template<typename T>
class  MyDeque{
private:
    size_t SIZE = 32;
    size_t _size{};
    T** _bucket;
    size_t _begin_index{};
    size_t _end_index{};
    size_t _begin{};
    size_t _end{};
    size_t _capacity;
    size_t _resize{};

    void resize() {
        T** new_arr = new T*[_capacity * 2];

        for (size_t i = 0; i < _capacity * 2; ++i) {
            new_arr[i] = new T[SIZE];
        }

        size_t new_begin_index = (_capacity * 2 - _size) / SIZE;
        size_t new_begin = (_capacity * 2 - _size) % SIZE;

        for (size_t i = _size; i > 0; --i) {
            new_arr[new_begin_index][new_begin] = _bucket[(_begin_index + (_size - i) / SIZE) % _capacity][(_size - i) % SIZE];
            new_begin--;
            if (new_begin == SIZE - 1) {
                new_begin_index--;
                new_begin = SIZE - 1;
            }
        }

        for (size_t i = 0; i < _capacity; ++i) {
            delete[] _bucket[i];
        }
        delete[] _bucket;

        _capacity *= 2;
         // _begin_index = new_begin_index;
        // _begin = new_begin - 1;
        // _end_index = (_size - 1) / SIZE;
        // _end = (_size - 1) % SIZE;
        _begin_index = 0;
        _begin= 0;
        _end_index = _size;
        _end = 0;
        _bucket = new_arr;
    }


public :

    MyDeque() : _size(0), _capacity(SIZE), _begin_index(SIZE/2), _end_index(SIZE/2), _begin(0), _end(0) {
        _bucket = new T*[SIZE];
        for (size_t i = 0; i < SIZE; ++i) {
            _bucket[i] = new T[SIZE];
        }

        _begin_index = SIZE/2;
        _end_index = SIZE/2;
    }

    void clear() {
        for (size_t i = 0; i < _capacity; ++i) {
            delete[] _bucket[i];
        }

        delete[] _bucket;
        _bucket = new T*[SIZE];
        for (size_t i = 0; i < SIZE; ++i) {
            _bucket[i] = new T[SIZE];
        }

        _size = 0;
        _begin_index = SIZE/2;
        _end_index = SIZE/2;
        _begin = 0;
        _end = 0;
    }

    ~MyDeque(){
        clear();
    }

    void push_back(T value){
        if(_end_index == _size){
            resize();
        }

        if(_end == SIZE){
            _end = 0;
            _end_index++;
        }

        _bucket[_end_index][_end] = value;

        _end++;
        _size++;
    }

    void push_front(T value) {
        if (_begin == 0  && _begin_index == 0){
            resize();
        }

        if (_begin == 0) {
            _begin = SIZE - 1;
             _begin_index = _begin_index == 0 ? _capacity - 1 : _begin_index - 1;
        }
        else
        {
            _begin--;
            if (_begin_index > 0 && _begin == SIZE - 1) {
                _begin_index--;
            }
        }

        _bucket[_begin_index][_begin] = value;
        _size++;
    }

    void pop_back(){
        if(_size == 0 ) { throw std::out_of_range("Index out of range"); }

        if(_end == 0){
            _end_index --;
            _end = SIZE - 1;
        }
        else{
            _end--;
        }
        _size--;
    }

    void pop_front(){
        if(_size == 0 ) { throw std::out_of_range("Index out of range"); }
        _begin++;
        if(_begin == SIZE){
            _begin_index++;
            _begin++;
        }
            _size--;
    }

    const T& at(size_t index) const {
        if(index >= _size){ throw std::out_of_range("Index out of range"); }
        return _bucket[(_begin_index + index / SIZE ) % _capacity + (((index + _begin))) / SIZE][(index + _begin) % SIZE];
    }

    T& operator[](size_t index){
        if(index >= _size){ throw std::out_of_range("Index out of range"); }

        return _bucket[(_begin_index + index / SIZE) % _capacity][index % SIZE];
    }

    QString toString(){

        QString res = "";
        for(size_t i = 0; i < _size; ++i){
            res += std::to_string(at(i)) +  " ";
        }
        return res;
    }

    bool isEmpty() {
        return _size == 0;
    }

    size_t capacity() {
        return _capacity;
    }


    Iterator<T> begin(){
        return (this, 0);
    }

    Iterator<T> end(){
        return (this, _size);
    }

};


template<typename T>
class Iterator {
private:
    MyDeque<T> *deque;
    size_t index;
public:

    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::random_access_iterator_tag;

    Iterator(MyDeque<T> *deque, size_t index) : deque(deque), index(index) {
    }

    ~Iterator() {

    }

    T& operator*(){
        return deque[index];
    }

    const T& operator*() const {
        return deque[index];
    }

    const Iterator operator++(int){
        Iterator temp = *this;
        ++index;
        return temp;
    }

    const Iterator operator--(int){
        Iterator temp = *this;
        --index;
        return temp;
    }

    Iterator operator--(){
        --index;
        return* this;
    }

    Iterator operator++(){
        ++index;
        return* this;
    }

    Iterator operator+(size_t element) {
        index += element;
        return* this;
    }

    Iterator operator-(size_t element){
        index -= element;
        return* this;
    }


    Iterator operator+(difference_type n) const {
        return Iterator(deque, index + n);
    }

    Iterator operator-(difference_type n) const {
        return Iterator(deque, index - n); }


    difference_type operator-(const Iterator &other) {
        return index - other.index;
    }

    bool operator == (const Iterator &other){
        return this->index == other.index;
    }

    bool operator >(const Iterator &other){
        return this->index > other.index;
    }

    bool operator < (const Iterator &other){
        return this->index > other.index;
    }

    bool operator !=(const Iterator &other){
        return this->index != other.index;
    }

    bool operator >= (const Iterator &other){
        return this->index >= other.index;
    }

    bool operator <= (const Iterator &other){
        return this->index <= other.index;
    }

};
#endif // MYDEQUEUE_H
