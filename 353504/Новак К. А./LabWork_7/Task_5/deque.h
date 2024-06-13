#ifndef DEQUE_H
#define DEQUE_H


#include <QDebug>
#include <cstddef>
#include <cstdint>
#include <iterator>

constexpr size_t BLOCK_SIZE = 32;
constexpr size_t Base_Capacity = 10;
constexpr int64_t Nothing = -1;

template<typename T>
class DequeIterator;

template<typename T> class Deque
{
private:
    T **data;
    size_t _size;
    size_t _capacity;
    int64_t _frontBlock;
    int64_t _frontIndex;
    int64_t _backBlock;
    int64_t _backIndex;


    void expandMap(){
        size_t new_capacity = (_capacity * 2);
        T** new_data = reinterpret_cast<T**>(new int8_t[sizeof(T*) * new_capacity]);

        size_t start = _frontBlock;
        for(size_t i = 0; i < _capacity; ++i){
            new_data[i] = data[start];
            start = (1 + start) % _capacity;
        }

        for(size_t i = _capacity; i < new_capacity; ++i){
            new_data[i] = reinterpret_cast<T*>(new int8_t[sizeof(T) * BLOCK_SIZE]);
        }

        delete[] reinterpret_cast<int8_t *>(data);
        data = new_data;
        _capacity = new_capacity;
        _frontBlock = 0;
        _backBlock = (_size - 1) / BLOCK_SIZE;
    }
public:

    explicit Deque()
        : _size(0)
        , _capacity(2)
        , _frontBlock(Nothing)
        , _frontIndex(Nothing)
        , _backBlock(Nothing)
        , _backIndex(Nothing)
    {
        data = reinterpret_cast<T**>(new int8_t*[sizeof(T*) * _capacity]);

        for(int i = 0; i < _capacity; ++i){
            data[i] = reinterpret_cast<T*>(new char[sizeof(T) * BLOCK_SIZE]);
        }
    }

    ~Deque(){
        for (size_t i = 0; i < _size; ++i) {
            data[(_frontBlock + (i + _frontIndex) / BLOCK_SIZE) % _capacity]
                [(i + _frontIndex) % BLOCK_SIZE]
                    .~T();
        }

        for (size_t i = 0; i < _capacity; ++i) {
            delete[] reinterpret_cast<int8_t *>(data[i]);
        }

        delete[] reinterpret_cast<int8_t *>(data);
    }

    //Pushs
    void push_back(T item){
        if ((_size == _capacity * BLOCK_SIZE)
            || (((static_cast<int64_t>((_backBlock + 1) % _capacity)) == _frontBlock)
                && _backIndex == BLOCK_SIZE - 1)) {
            expandMap();
        }

        if (_frontBlock == Nothing) {
            _frontBlock = 0;
            _frontIndex = 0;
            _backBlock = 0;
            _backIndex = 0;
        } else {
            _backIndex = (_backIndex + 1) % BLOCK_SIZE;
            if (_backIndex == 0) {
                _backBlock = (_backBlock + 1) % _capacity;
            }
        }

        new (&data[_backBlock][_backIndex]) T(std::move(item));
        ++_size;
    }

    void push_front(T value)
    {
        if (_size == _capacity * BLOCK_SIZE
            || (((static_cast<int64_t>((_frontBlock - 1 + _capacity) % _capacity)) == _backBlock)
                && _frontIndex == 0)) {
            expandMap();
        }

        if (_frontBlock == Nothing) {
            _frontBlock = 0;
            _frontIndex = 0;
            _backBlock = 0;
            _backIndex = 0;
        } else {
            _frontIndex = (_frontIndex - 1 + BLOCK_SIZE) % BLOCK_SIZE;
            if (_frontIndex == BLOCK_SIZE - 1) {
                _frontBlock = (_frontBlock - 1 + _capacity) % _capacity;
            }
        }

        new (&data[_frontBlock][_frontIndex]) T(std::move(value));
        ++_size;
    }

    //Pops
    void pop_back(){
        if(empty()){
            return;
        }

        data[_backBlock][_backIndex].~T();
        _backIndex = (_backIndex - 1 + BLOCK_SIZE) % BLOCK_SIZE;

        if (_backIndex == BLOCK_SIZE - 1) {
            _backBlock = (_backBlock - 1 + _capacity) % _capacity;
        }

        --_size;
    }

    void pop_front(){
        if(empty()){
            return;
        }

        data[_frontBlock][_frontIndex].~T();
        _frontIndex = (_frontIndex + 1) % BLOCK_SIZE;

        if (_frontIndex == 0) {
            _frontBlock = (_frontBlock + 1) % _capacity;
        }

        --_size;
    }

    //Operators
    T &operator[](size_t index){
        index = index % _size;

        return data[(_frontBlock + (index + _frontIndex) / BLOCK_SIZE) % _capacity][(index + _frontIndex) % BLOCK_SIZE];
    }

    const T &operator[] (size_t index)const{
        index = index % _size;

        return data[(_frontBlock + (index + _frontIndex) / BLOCK_SIZE) % _capacity][(index + _frontIndex) % BLOCK_SIZE];
    }

    const T &at (size_t index)const{
        index = index % _size;

        return data[(_frontBlock + (index + _frontIndex) / BLOCK_SIZE) % _capacity][(index + _frontIndex) % BLOCK_SIZE];
    }

    //Funcs
    size_t size() const{
        return _size;
    }

    bool empty() const{
        return _size == 0;
    }

    void clear(){
        while (!empty()) {
            pop_back();
        }
    }

    DequeIterator<T> begin(){
        return DequeIterator(this, 0);
    }

    DequeIterator<T> end(){
        return DequeIterator(this, _size);
    }
};

template<typename T>
class DequeIterator
{
private:
    Deque<T>* _deque;
    size_t index;

public:
    using difference_type = std::ptrdiff_t;

    DequeIterator(Deque<T> *deque, size_t index) : _deque(deque), index(index){} //


    T &operator*() { return (*_deque)[index]; }
    const T& operator*()const{return (*_deque)[index];}

    DequeIterator operator++(){
        index = (index + 1) % (_deque->size());
        return *this;
    }
    DequeIterator operator--(){
        index = (index - 1) % (_deque->size());
        return *this;
    }

    const DequeIterator operator++(int){
        Deque temp = *this;
        index = (index + 1) % (_deque->size());
        return temp;
    }
    const DequeIterator operator--(int){
        Deque temp = *this;
        index = (index - 1) % (_deque->size());
        return temp;
    }

    DequeIterator operator+(difference_type n) const { return DequeIterator(_deque, index + n); }
    DequeIterator operator-(difference_type n) const { return DequeIterator(_deque, index - n); }
    difference_type operator-(const DequeIterator &other) { return index - other.index; }
    bool operator==(const DequeIterator &other) const { return index == other.index; }
    bool operator!=(const DequeIterator &other) const { return index != other.index; }
    bool operator<(const DequeIterator &other) const { return index < other.index; }
    bool operator>(const DequeIterator &other) const { return index > other.index; }
    bool operator<=(const DequeIterator &other) const { return index <= other.index; }
    bool operator>=(const DequeIterator &other) const { return index >= other.index; }
};

#endif // DEQUE_H
