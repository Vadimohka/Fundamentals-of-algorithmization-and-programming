#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstddef>
template<typename T>
class Iterator
{
private:

    T *it;

public:


    explicit Iterator(T *t) : it(t){}

    ~Iterator() = default;

    const T *getIteratorAddress() const {
        return it;
    }

    T &operator*() const {
        return *it;
    }

    T *operator->() const {
        return it;
    }

    //*this для того чтобы получить объект класса iterator а не указатель на объект класса iterator
    Iterator operator++() {
        ++it;
        return *this;
    }

    Iterator &operator--() {
        --it;
        return *this;
    }

    Iterator operator++(int) {
        Iterator temp(*this);
        ++(*this);
        return temp;
    }

    Iterator operator--(int) {
        Iterator temp(*this);
        --(*this);
        return temp;
    }

    Iterator operator+(int n){
        return Iterator(it + n);
    }

    Iterator operator-(int n){
        return Iterator(it - n);
    }

    Iterator &operator+=(size_t n) {
        it += n;
        return *this;
    }

    Iterator &operator-=(size_t n) {
        it -= n;
        return *this;
    }

    T operator[](size_t n) {
        return it[n];
    }

    bool operator==(const Iterator& a) {
        return it == a.it;
    }

    bool operator !=(const Iterator& a) {
        return it != a.it;
    }

};

template<typename T>
class ReverseIter
{
private:

    T *it;

public:

    explicit ReverseIter
(T *t) : it(t){}

    ~ReverseIter
() = default;

    const T *base() const {
        return it;
    }

    T &operator*() const {
        return *it;
    }

    T *operator->() const {
        return it;
    }

    ReverseIter
 operator++() {
        --it;
        return *this;
    }

    ReverseIter
 &operator--() {
        ++it;
        return *this;
    }

    ReverseIter
 operator++(int) {
        ReverseIter
     temp(*this);
        --(*this);
        return temp;
    }

    ReverseIter
 operator--(int) {
        ReverseIter
     temp(*this);
        --(*this);
        return temp;
    }

    ReverseIter
 operator+(int n){
        return ReverseIter
    (it - n);
    }

    ReverseIter
 operator-(int n){
        return ReverseIter
    (it + n);
    }

    ReverseIter
 &operator+=(size_t n) {
        it -= n;
        return *this;
    }

    ReverseIter
 &operator-=(size_t n) {
        it += n;
        return *this;
    }

    T operator[](size_t n) {
        return it[n];
    }

    bool operator==(const ReverseIter
& a) {
        return it == a.it;
    }


    bool operator !=(const ReverseIter
& a) {
        return it != a.it;
    }



};

#endif