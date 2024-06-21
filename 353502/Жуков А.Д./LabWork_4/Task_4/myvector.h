#ifndef MYVECTOR_H
#define MYVECTOR_H

//#include <iostream>
#include <vector>
#include <string>
#include <mybector_global.h>

template <typename Type>
class MyVector
{
    int _size;
    int _capacity;
    Type * array;

    void allocate(){
        _capacity *= 2;
        Type * buff = new Type[_capacity]{};
        for (int i = 0; i < _size; ++i) {
            buff[i] = array[i];
        }
        delete array;
        array = buff;
    }
    void allocate(int add){
        _capacity += add;
        Type * buff = new Type[_capacity]{};
        for (int i = 0; i < _size; ++i) {
            buff[i] = array[i];
        }
        delete[] array;
        array = buff;
    }
    void ChangeArr(Type *newArr) { delete[] array; array = newArr; }

public:
    class Iterator;

    explicit MyVector(int size = 1) : _size(size), _capacity(size)
    {
        if (size > 0) {
            array = new Type[size];
        } else {
            array = new Type[1];
        }
    }
    explicit MyVector(Type *arr) : _size(size), _capacity(size), array(arr)
    {}

    ~MyVector()
    {
        delete[] array;
        array = nullptr;
    }

    Type & operator[](const int & n)
    {
        if (n > -1 && n < _size) {
            return array[n];
        }
        return Type{};
    }

    Iterator begin() { return Iterator(array); }
    Iterator end() { return Iterator(array + _size); }
    const Iterator cbegin() { Type* ptr = array; return Iterator(ptr); }
    const Iterator cend() { Type* ptr = array + _size; return Iterator(ptr); }
    Iterator rbegin() { return Iterator(array - 1); }
    Iterator rend() { return Iterator(array + _size - 1); }

    const Type & back() { return array[_size - 1]; }
    const Type & front() { return array[0]; }
    Type & at(int pos) { return array[pos]; }
    Type * data() { return array; }

    void resize(const int & size){
        if (size == _size) {
            return;
        } else if (size < _size) {
            Type * buff = new Type[size]{};
            for (int i = 0; i < _size; ++i) {
                buff[i] = array[i];
            }
            delete[] array;
            array = buff;
        } else {
            Type * buff = new Type[size]{};
            for (int i = 0; i < _size; ++i) {
                buff[i] = array[i];
            }
            _capacity = size;
        }
        _size = size;
    }
    void clear() {
        delete[] array;
        array = new Type[1]{};
        _size = 0;
        _capacity = 1;
    }
    void assign(const int & count, const Type & value) {
        this->clear();
        array = new Type[count];
        _size = _capacity = count;
        for (int i = 0; i < _size; ++i) {
            array[i] = value;
        }
    }
    void swap( MyVector<Type> & vect )
    {
        Type* buffArr = nullptr;
        buffArr = array;
        array = vect.data();
        vect.ChangeArr(buffArr);
    }
    void insert(int pos, Type element)
    {
        if (_size == _capacity && pos >= 0 && pos <= _size) {
            allocate();
            _size++;
        } else {
            return;
        }
        Type buff = array[pos];
        array[pos] = element;
        for (int i = pos + 1; i < _size; i++)
        {
            array[i] = buff;
            buff = array[i + 1];
        }
    }
    void insert(int pos, int size, Type *elements)
    {
        if (_size + size >= _capacity && pos >= 0 && pos <= _size) {
            while (_size + size >= _capacity) {
                allocate();
            }
            _size += size;
        } else {
            return;
        }
        Type* tempArr = new Type[_size];
        for (int i = 0; i < pos; i++)
        {
            tempArr[i] = array[i];
        }
        for (int i = pos; i < (_size - size); i++)
        {
            tempArr[size + i] = array[i];
        }
        delete[] tempArr;
        tempArr = nullptr;
    }

    void emplace(int pos, Type el) { insert(pos, el); }
    void emplace_back(const Type & el) { emplace(_size, el); }
    void push_back(const Type & el) { emplace(_size, el); }
    void erase(const int & pos, const int & amount) {
        if ((pos >= 0 || pos < _size) && amount < _size - pos) {
            _size -= amount;
        } else {
            return;
        }
        for (int i = pos; i < _size; i++) {
            array[i] = array[i + amount];
        }
        for (int i = _size; i < _capacity; i++) {
            array[i] = Type{};
        }
    }
    void erase(const int & pos) { erase(pos, 1); }
    void pop_back() { erase(_size - 1, 1); }

    int size() { return _size; }
    int capacity() { return _capacity; }
    size_t max_size() const { return static_cast<size_t>(-1) / sizeof(Type); }
    void reserve(int add) { allocate(add); }

    bool empty() { return _size == 0; }

    class Iterator
    {
        Type * current;

    public:
        explicit Iterator(Type * first) : current(first) {}

        Iterator operator + (int num) { return Iterator(current + num); }
        Iterator operator - (int num) { return Iterator(current - num); }

        Iterator operator ++ (int) { return *--this; }
        Iterator operator ++ () { return Iterator(current++); }
        Iterator operator -- (int) { return *--this; }
        Iterator operator -- () { return Iterator(current--); }

        bool operator == (const Iterator iter) { return this->current == iter.current; }
        bool operator != (const Iterator iter) { return this->current != iter.current; }

        Type & operator * () { return *current; }
    };
};

/*
template<typename Type>
std::ostream & operator << (std::ostream & out, const MyVector<Type> & vector)
{
    for (const Type & element : vector)
    {
        out << element << " ";
        out << std::endl;
    }
    return out;
}
*/

#endif // MYVECTOR_H
