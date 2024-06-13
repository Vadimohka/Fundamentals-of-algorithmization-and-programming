#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <QDebug>

template <typename T>

class Iterator
{
    T* pointer;
public:

    explicit Iterator(T* ptr){
        pointer = ptr;
    }

    Iterator<T> &operator++() {
        pointer++;
        return *this;
    }
    Iterator<T> &operator++(int){
        Iterator<T> temp = *this;
        ++pointer;
        return temp;
    }
    Iterator<T> &operator--(){
        pointer--;
        return *this;
    }
    Iterator<T> &operator--(int){
        Iterator<T> temp = *this;
        --pointer;
        return temp;
    }

    T &operator*() {
        return *pointer;
    }
};

template <typename T>
class RIterator {
    T* pointer;

public:

    explicit RIterator(T* ptr){
        pointer = ptr;
    }

    RIterator<T> &operator++() {
        --pointer;
        return *this;
    }

    RIterator<T> operator++(int) {
        RIterator<T> temp = *this;
        --pointer;
        return temp;
    }

    RIterator<T> &operator--() {
        ++pointer;
        return *this;
    }

    RIterator<T> operator--(int) {
        RIterator<T> temp = *this;
        ++pointer;
        return temp;
    }

    T &operator*() {
        return *pointer;
    }
};

#endif // ITERATOR_H
